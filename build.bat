@echo off
setlocal

:: Check if we're in a Visual Studio Developer Command Prompt
if not defined VSCMD_VER (
    echo MSVC build environment is not initialized.
    echo Please open the "x64 Native Tools Command Prompt for Visual Studio" and run this script from there.
    pause
    exit /b
)

echo Environment detected. Compiling lcfg.exe...

cl /std:c++20 /utf-8 /EHsc /I src\include src\func\*.cpp src\lcfg.cpp /link /LIBPATH:src lua54.lib Advapi32.lib /OUT:lcfg.exe /MACHINE:X64

if %errorlevel% neq 0 (
    echo Build failed
) else (
    echo Build succeeded
)

pause
endlocal
