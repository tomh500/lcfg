#include "../../utils.hpp"

int luaFunc_src(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 1)
        luaL_error(L, "Function 'src' expects 1 argument.");
    const auto s = string(luaL_checkstring(L,1));
    event.pushEvent(s);
    return 0;
}
void registerLuaSrcFunction(lua_State *L)
{
    lua_register(L, "src", luaFunc_src);
}