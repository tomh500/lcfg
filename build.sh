if g++ ./src/func/*.cpp ./src/lcfg.cpp -I./src/include -I/usr/include/lua5.4 -llua5.4 -o lcfg -std=c++20;then
    echo build successfully
    ./lcfg test.lcfg
else
    echo build failed
fi