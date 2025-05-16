#include "../../utils.hpp"

int luaFunc_jump(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 0)
        luaL_error(L, "Function 'jump' expects 0 argument.");
    event.pushEvent("+jump");
    event.pushEvent("-jump");
    return 0;
}
void registerLuaJumpFunction(lua_State *L)
{
    lua_register(L, "jump", luaFunc_jump);
}