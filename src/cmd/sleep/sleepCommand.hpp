#include "../../utils.hpp"

int luaFunc_sleep(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum == 0 || argNum > 2)
        luaL_error(L, "Function 'sleep' expects 1 or 2 argument(s).");
    int tick = luaL_checkinteger(L, 1);
    if (argNum == 2)
    {
        const auto s = string(luaL_checkstring(L, 2));
        if (s == "t" || s == "tick")
            tick = tick;
        else if (s == "s" || s == "sec" || s == "second")
            tick = tick * TICKRATE;
        else
            luaL_error(L, format("Unkown time type '{}'.", s).c_str());
    }
    event.sleep(tick);
    return 0;
}
void registerLuaSleepFunction(lua_State *L)
{
    lua_register(L, "sleep", luaFunc_sleep);
}