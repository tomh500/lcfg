#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

bool HeaderChecker(const string& filepath) {
    ifstream fin(filepath);
    if (!fin.is_open()) {
        cerr << "无法打开 Lua 脚本文件：" << filepath << "\n";
        return false;
    }

    string firstLine;
    getline(fin, firstLine);
    fin.close();

    regex pattern(R"(^\s*LCFG_VERSION\s*\(\s*\d+\s*\)\s*$)");

    if (regex_match(firstLine, pattern)) {
        return true;
    } else {
        cerr << "错误：未声明 lcfg 语法版本号\n";
        cerr << "Error: LCFG version declaration missing.\n";
        return false;
    }
}
