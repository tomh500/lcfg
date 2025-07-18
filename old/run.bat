g++ ./src/compiler/lcfg.cpp -o lcfg.exe -std=c++23 -O2 -lm -Wall
@echo off
if %errorlevel% neq 0 (
    exit /b
)
@echo on

lcfg.exe test.lcfg
