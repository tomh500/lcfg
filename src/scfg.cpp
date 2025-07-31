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
    ARG::init(argc,argv);

    string scriptPath = ARG::cmdl[1];
    
    auto& loc = scfg::localization::LocalizationManager::getInstance();
    log(loc.getText("logs.scfg_running"));

    // 创建新的 Lua 状态
    lua_State *L = luaL_newstate();
    luaL=L;
    lua_setwarnf(L, warning_func, nullptr);

    if (L == nullptr)
    {
        cerr << loc.getText("errors.lua_state_failed") << endl;
        return 1;
    }

    // 打开 Lua 标准库
    luaL_openlibs(L);

    // 注册 C++ 函数到 Lua
    registerLuaFunctions(L);

    // 执行 Lua 脚本
    if (luaL_dofile(L, scriptPath.c_str()) != LUA_OK)
    {
        cerr << loc.getText("errors.script_execution_error", {lua_tostring(L, -1)}) << endl;
        lua_pop(L, 1); // 移除错误消息
        lua_close(L);
        return 1;
    }

    // check
    log(loc.getText("logs.ok_process", {std::to_string(event.time())}));

    // generate
    event.generate(fs::current_path() / fs::path(argv[1]).stem(), L);

    // 清理
    lua_close(L);
    return 0;
}
