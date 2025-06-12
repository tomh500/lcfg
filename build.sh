if g++ ./src/func/FlagDevices.cpp ./src/scfg.cpp -I./src/include -I/usr/include/lua5.4 -llua5.4 -o lcfg -std=c++20;then
    echo build successfully
    ./lcfg test.scfg
else
    echo build failed
fi