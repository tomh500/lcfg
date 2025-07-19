#include "cmd/baseCommand.hpp"
#include "cmd/sleep/sleepCommand.hpp"
#include "cmd/src/srcCommand.hpp"
#include "cmd/setExecPath/setExecPathCommand.hpp"
#include "cmd/jump/jumpCommand.hpp"
#include "cmd/jumpbug/jumpbugCommand.hpp"
#include "cmd/angle/angle.hpp"
#include "cmd/baseInstantCommand.hpp"
#include "cmd/boost/boostCommand.hpp"
#include "cmd/misc/miscCommand.hpp"
#include "utils.hpp"
#include "include/Global.h"

lua_State* luaL;
int g_lcfgVersion = 1; 

int LCFG_VERSION(lua_State* L) {
    int version = luaL_checkinteger(L, 1);
    g_lcfgVersion = version;
    lua_pushboolean(L, true);
    lua_setglobal(L, "_LCFG_VER_CHECKED");
    return 0;
}



void registerLuaFunctions(lua_State *L)
{
    registerLuaBaseFunctions(L);
    registerLuaSleepFunction(L);
    registerLuaSrcFunction(L);
    registerLuaSetExecPathFunction(L);
    registerLuaJumpFunction(L);
    registerLuaJumpbugFunction(L);
    registerLuaAngleFunction(L);
    registerLuaBaseInstantFunctions(L);
    registerLuaBoostFunction(L);
    registerLuaMiscFunction(L);
    lua_register(L, "LCFG_VERSION", LCFG_VERSION);

}

void warning_func(void *ud, const char *msg, int tocont)
{
    if (!tocont)
        std::cerr << "[Lua warning] ";
    std::cerr << msg;
    if (!tocont)
        std::cerr << std::endl;
}
int main(int argc, char *argv[])
{
    #ifdef _WIN32
    system("chcp 65001>nul");
    #endif 
    ARG::init(argc,argv);

    string scriptPath = ARG::cmdl[1];
    
    log("lcfg is running.");

    // 创建新的 Lua 状态
    lua_State *L = luaL_newstate();
    luaL=L;
    lua_setwarnf(L, warning_func, nullptr);

    if (L == nullptr)
    {
        cerr << "Failed to create Lua state." << endl;
        return 1;
    }

    // 打开 Lua 标准库
    luaL_openlibs(L);

    // 注册 C++ 函数到 Lua
    registerLuaFunctions(L);

    RemoteChecker();

    if (!HeaderChecker(scriptPath)) {
         return 101; 
    }

    luaL_loadfile(L, "your_script.lua");
    lua_pcall(L, 0, 0, 0);

   
    // 执行 Lua 脚本
    if (luaL_dofile(L, scriptPath.c_str()) != LUA_OK)
    {
        cerr << "Error executing script: " << lua_tostring(L, -1) << endl;
        lua_pop(L, 1); // 移除错误消息
        lua_close(L);
        return 1;
    }

    // check
    log(format("ok process lcfg file. end with current tick={}.", event.time()));

    // generate
    event.generate(fs::current_path() / fs::path(argv[1]).stem(), L);
    //FlagDevicesWithEnv();
    FlagDevicesWithReg();
    // 清理
    lua_close(L);
    return 0;
}
