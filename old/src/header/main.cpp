#include //标准库头文件
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <chrono>
#include <filesystem>

#include "lcfg.hpp"
using namespace std;
int main(){
    lcfg::lcfg lcfg("res.txt");
    lcfg::command forward_and_jump({

    });
    lcfg.gen();
    return 0;
}