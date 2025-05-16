#include "../../utils.hpp"

int luaFunc_jumpbug(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 0)
        luaL_error(L, "Function 'jumpbug' expects 0 argument.");
        
    event.pushEvent("+duck");
    event.sleep(1);
    event.pushEvent("-duck");
    event.pushEvent("+jump");
    event.pushEvent("-jump");
    return 0;
}
void registerLuaJumpbugFunction(lua_State *L)
{
    lua_register(L, "jumpbug", luaFunc_jumpbug);
}