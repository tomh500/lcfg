#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

void RemoteChecker() {
#ifdef _WIN32
    std::string cmd = "tasklist";
    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe) {
        std::cerr << "无法执行任务列表命令\n";
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    bool found = false;
    while (fgets(buffer, sizeof(buffer), pipe)) {
        std::string line(buffer);
        if (line.find("todesk.exe") != std::string::npos ||
            line.find("sunloginclient.exe") != std::string::npos ||
            line.find("sunlogin.exe") != std::string::npos) {
            found = true;
            break;
        }
    }
    _pclose(pipe);

    if (found) {
        std::cout << "检测到远程软件（ToDesk 或 向日葵），请关闭后重新编译。\n";
        exit(EXIT_FAILURE);
    }
#endif
}
