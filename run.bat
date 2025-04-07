g++ ./src/compiler/scfg.cpp -o scfg.exe -O2 -std=c++23 -O2 -lm -Wall
echo end build
scfg.exe test.scfg