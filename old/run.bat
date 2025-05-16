g++ ./src/compiler/scfg.cpp -o scfg.exe -std=c++23 -O2 -lm -Wall
@echo off
if %errorlevel% neq 0 (
    exit /b
)
@echo on

scfg.exe test.scfg
