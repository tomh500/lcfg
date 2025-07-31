#ifndef SCFG_LOCALIZATION_MANAGER_HPP
#define SCFG_LOCALIZATION_MANAGER_HPP

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <filesystem>
#include "exceptions/LocalizationException.hpp"

namespace fs = std::filesystem;

namespace scfg {
namespace localization {

class LocalizationManager {
private:
    static std::unique_ptr<LocalizationManager> instance;
    
    std::string currentLanguage;
    std::map<std::string, std::string> translations;
    std::string localeDir;
    std::map<std::string, std::string> fallbackTranslations;
    
    // Приватный конструктор для singleton
    LocalizationManager();
    
    // Инициализация fallback переводов
    void initializeFallbackTranslations();
    
    // Загрузка файла перевода
    void loadTranslationFile(const std::string& language);
    
    // Замена параметров в строке
    std::string formatString(const std::string& str, const std::vector<std::string>& args) const;

public:
    // Получение единственного экземпляра
    static LocalizationManager& getInstance();
    
    // Удаление копирования
    LocalizationManager(const LocalizationManager&) = delete;
    LocalizationManager& operator=(const LocalizationManager&) = delete;
    
    // Установка языка
    void setLanguage(const std::string& language);
    
    // Получение текста по ключу
    std::string getText(const std::string& key) const;
    
    // Получение текста с параметрами
    std::string getText(const std::string& key, const std::vector<std::string>& args) const;
    
    // Проверка наличия ключа
    bool hasKey(const std::string& key) const;
    
    // Получение списка доступных языков
    std::vector<std::string> getAvailableLanguages() const;
    
    // Установка директории с переводами
    void setLocaleDirectory(const std::string& directory);
    
    // Получение текущего языка
    std::string getCurrentLanguage() const;
};

} // namespace localization
} // namespace scfg

#endif // SCFG_LOCALIZATION_MANAGER_HPP