#include <iostream>
#include <cstdlib>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;



int FlagDevicesWithEnv() {
#ifdef _WIN32
    const string key = "ScfgExecuted";
    const string value = "1";
    const string env_str = key + "=" + value;

    if (_putenv(env_str.c_str()) != 0) {
       cerr << "Failed to set environment variable for session.\n";
        return 2;
    }

    string cmd = "setx " + key + " " + value + " > nul";
    if (system(cmd.c_str()) != 0) {
        cerr << "Failed to persist environment variable using setx.\n";
        return 1;
    }

    return 0;
#else
    cerr << "Non-Windows platform detected. Skipping environment variable setup.\n";
    return -1;  
#endif
}


void FlagDevicesWithReg()
{
#ifdef _WIN32
    HKEY hKey;
    const wchar_t* subkey = L"Software\\LCFG";
    const wchar_t* valueName = L"LCFGHasRun";
    DWORD value = 1;

    LONG result = RegCreateKeyExW(
        HKEY_CURRENT_USER,
        subkey,
        0,
        NULL,
        0,
        KEY_WRITE,
        NULL,
        &hKey,
        NULL);

    if (result == ERROR_SUCCESS)
    {
        result = RegSetValueExW(
            hKey,
            valueName,
            0,
            REG_DWORD,
            reinterpret_cast<const BYTE*>(&value),
            sizeof(value));

        if (result != ERROR_SUCCESS)
        {
            std::cerr << "Failed to set registry value LCFGHasRun" << std::endl;
        }
        else
        {
            std::cerr << "Registry value LCFGHasRun = 1 written successfully" << std::endl;
        }

        RegCloseKey(hKey);
    }
    else
    {
        std::cerr << "Failed to open/create registry key for LCFG" << std::endl;
    }
#else
    std::cerr << "markLCFGHasRun is only implemented for Windows platforms" << std::endl;
#endif
}