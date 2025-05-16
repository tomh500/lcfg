#include "cmd/baseCommand.hpp"
#include "cmd/sleep/sleepCommand.hpp"
#include "utils.hpp"

void registerLuaFunctions(lua_State *L)
{
    registerLuaBaseFunctions(L);
    registerLuaSleepFunction(L);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <script.lua>" << endl;
        return 1;
    }

    const char *scriptPath = argv[1];
    // 打开输出文件

    // 创建新的 Lua 状态
    lua_State *L = luaL_newstate();
    if (L == nullptr)
    {
        cerr << "Failed to create Lua state." << endl;
        return 1;
    }

    // 打开 Lua 标准库
    luaL_openlibs(L);

    // 注册 C++ 函数到 Lua
    registerLuaFunctions(L);

    // 执行 Lua 脚本
    if (luaL_dofile(L, scriptPath) != LUA_OK)
    {
        cerr << "Error executing script: " << lua_tostring(L, -1) << endl;
        lua_pop(L, 1); // 移除错误消息
        lua_close(L);
        return 1;
    }

    // check
    log(format("ok process scfg file. end with current tick={}.",event.time()));

    // 清理
    lua_close(L);
    return 0;
}
