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

    regex pattern(R"(#LCFG_VERSION\s*=\s*\d+)");
    if (regex_search(firstLine, pattern)) {
        return true;
    } else {
        cerr << "未声明 LCFG 版本号，请在 Lua 文件第一行添加：LCFG_VERSION=<版本号>\n";
        cerr << "Missing LCFG version declaration. Please add: LCFG_VERSION=<version number> on the first line of your Lua script.\n";
        return false;
    }
}
