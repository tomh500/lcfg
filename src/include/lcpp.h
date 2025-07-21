#ifndef LCPP_H
#define LCPP_H

#include <vector>
#include <string>
#include <filesystem>

namespace lcpp
{

// 执行入口：兼容 lcfg.exe -lcpp <filepath>
int run(int argc, char* argv[]);

}

#endif // LCPP_H
