#include "LocalizationManager.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

namespace scfg {
namespace localization {

std::unique_ptr<LocalizationManager> LocalizationManager::instance = nullptr;

LocalizationManager::LocalizationManager() 
    : currentLanguage("en"), localeDir("locales") {
    initializeFallbackTranslations();
}

LocalizationManager& LocalizationManager::getInstance() {
    if (!instance) {
        instance = std::unique_ptr<LocalizationManager>(new LocalizationManager());
    }
    return *instance;
}

void LocalizationManager::initializeFallbackTranslations() {
    fallbackTranslations["errors.lua_state_failed"] = "Failed to create Lua state";
    fallbackTranslations["errors.script_execution_error"] = "Error executing script: {0}";
    fallbackTranslations["errors.file_not_found"] = "File not found: {0}";
    fallbackTranslations["errors.invalid_language"] = "Invalid language specified: {0}";
    fallbackTranslations["errors.translation_file_not_found"] = "Translation file not found: {0}";
    fallbackTranslations["errors.invalid_json_format"] = "Invalid JSON format in translation file: {0}";
    fallbackTranslations["logs.scfg_running"] = "scfg is running";
    fallbackTranslations["logs.workspace_info"] = "workspace: {0}";
    fallbackTranslations["logs.ok_process"] = "ok process scfg file. end with current tick={0}";
    fallbackTranslations["logs.receive_command"] = "receive {0}({1})";
    fallbackTranslations["logs.language_set"] = "Language set to: {0}";
    fallbackTranslations["logs.generating_cfg"] = "Generating CFG files...";
    fallbackTranslations["logs.cleanup_complete"] = "Cleanup complete";
    fallbackTranslations["cli.usage"] = "Usage: scfg <your_script_file_here>";
    fallbackTranslations["cli.help_description"] = "Show this help message";
    fallbackTranslations["cli.language_help"] = "Set language (en|ru)";
    fallbackTranslations["warnings.exec_path_not_set"] = "exec path has not been set! Are you sure?";
}

void LocalizationManager::setLanguage(const std::string& language) {
    currentLanguage = language;
    
    if (language != "en" && language != "ru") {
        throw LocalizationException("Invalid language: " + language);
    }
    
    loadTranslationFile(language);
}

void LocalizationManager::loadTranslationFile(const std::string& language) {
    std::string filename = localeDir + "/" + language + ".json";
    
    if (!fs::exists(filename)) {
        translations.clear();
        return;
    }
    
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return;
        }
        
        std::string content((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
        
        translations.clear();
        
        std::regex key_value_regex("\"([^\"]+)\":\\s*\"([^\"]*)\"");
        std::smatch match;
        
        std::string::const_iterator search_start(content.cbegin());
        while (std::regex_search(search_start, content.cend(), match, key_value_regex)) {
            std::string key = match[1];
            std::string value = match[2];
            
            value = std::regex_replace(value, std::regex("\\\\n"), "\n");
            value = std::regex_replace(value, std::regex("\\\\t"), "\t");
            value = std::regex_replace(value, std::regex("\\\\\""), "\"");
            
            translations[key] = value;
            search_start = match.suffix().first;
        }
        
    } catch (const std::exception& e) {
        translations.clear();
    }
}

std::string LocalizationManager::getText(const std::string& key) const {
    if (translations.find(key) != translations.end()) {
        return translations.at(key);
    }
    
    if (fallbackTranslations.find(key) != fallbackTranslations.end()) {
        return fallbackTranslations.at(key);
    }
    
    return "[" + key + "]";
}

std::string LocalizationManager::getText(const std::string& key, const std::vector<std::string>& args) const {
    std::string text = getText(key);
    
    for (size_t i = 0; i < args.size(); ++i) {
        std::string placeholder = "{" + std::to_string(i) + "}";
        size_t pos = text.find(placeholder);
        while (pos != std::string::npos) {
            text.replace(pos, placeholder.length(), args[i]);
            pos = text.find(placeholder, pos + args[i].length());
        }
    }
    
    return text;
}

bool LocalizationManager::hasKey(const std::string& key) const {
    return translations.find(key) != translations.end() || 
           fallbackTranslations.find(key) != fallbackTranslations.end();
}

std::vector<std::string> LocalizationManager::getAvailableLanguages() const {
    std::vector<std::string> languages;
    
    try {
        for (const auto& entry : fs::directory_iterator(localeDir)) {
            if (entry.is_regular_file()) {
                std::string filename = entry.path().filename().string();
                if (filename.length() > 5 && filename.substr(filename.length() - 5) == ".json") {
                    std::string lang = filename.substr(0, filename.length() - 5);
                    languages.push_back(lang);
                }
            }
        }
    } catch (const fs::filesystem_error&) {
        languages.push_back("en");
    }
    
    if (languages.empty()) {
        languages.push_back("en");
    }
    
    return languages;
}

void LocalizationManager::setLocaleDirectory(const std::string& directory) {
    localeDir = directory;
}

std::string LocalizationManager::getCurrentLanguage() const {
    return currentLanguage;
}

} // namespace localization
} // namespace scfg