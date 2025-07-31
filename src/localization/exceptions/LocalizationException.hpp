#ifndef SCFG_LOCALIZATION_EXCEPTION_HPP
#define SCFG_LOCALIZATION_EXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace scfg {
namespace localization {

class LocalizationException : public std::runtime_error {
public:
    explicit LocalizationException(const std::string& message)
        : std::runtime_error(message) {}
    
    explicit LocalizationException(const char* message)
        : std::runtime_error(message) {}
};

} // namespace localization
} // namespace scfg

#endif // SCFG_LOCALIZATION_EXCEPTION_HPP