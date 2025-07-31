#include <iostream>
#include "../../src/localization/LocalizationManager.hpp"

int main() {
    using namespace scfg::localization;
    
    auto& loc = LocalizationManager::getInstance();
    
    std::cout << "=== Тестирование системы локализации ===" << std::endl;
    
    // Тест 1: Базовые переводы
    std::cout << "1. Базовые переводы:" << std::endl;
    std::cout << "   English: " << loc.getText("logs.scfg_running") << std::endl;
    
    // Тест 2: Смена языка
    std::cout << "2. Смена языка на русский:" << std::endl;
    loc.setLanguage("ru");
    std::cout << "   Russian: " << loc.getText("logs.scfg_running") << std::endl;
    
    // Тест 3: Переводы с параметрами
    std::cout << "3. Переводы с параметрами:" << std::endl;
    std::cout << "   English: " << loc.getText("errors.script_execution_error", {"test.lua"}) << std::endl;
    
    loc.setLanguage("ru");
    std::cout << "   Russian: " << loc.getText("errors.script_execution_error", {"test.lua"}) << std::endl;
    
    // Тест 4: Доступные языки
    std::cout << "4. Доступные языки:" << std::endl;
    auto languages = loc.getAvailableLanguages();
    for (const auto& lang : languages) {
        std::cout << "   - " << lang << std::endl;
    }
    
    // Тест 5: Несуществующий ключ
    std::cout << "5. Несуществующий ключ:" << std::endl;
    std::cout << "   " << loc.getText("nonexistent.key") << std::endl;
    
    std::cout << "=== Тестирование завершено ===" << std::endl;
    
    return 0;
}