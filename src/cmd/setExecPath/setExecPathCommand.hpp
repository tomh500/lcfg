#include "../../utils.hpp"

int luaFunc_setExecPath(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 1)
        luaL_error(L, "Function 'setExecPath' expects 1 argument.");
    if (event.getExecPath_set())
    {
        luaL_error(L,"execPath can only be set once!");
    }
    event.setExecPath(string(luaL_checkstring(L, 1)));
    return 0;
}
void registerLuaSetExecPathFunction(lua_State *L)
{
    lua_register(L, "setExecPath", luaFunc_setExecPath);
}