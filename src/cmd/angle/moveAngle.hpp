#include "../../utils.hpp"
#include "angleUtils.hpp"

int luaFunc_moveAngle(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 2)
        luaL_error(L, "Function 'moveAngle' expects 3 arguments.");
    
    double yaw=luaL_checknumber(L,2);
    double pitch=luaL_checknumber(L,1);
    int t=luaL_checkinteger(L,3);
    
    ANGLE::moveAngle(yaw,pitch,t);
    return 0;
}

void registerLuaMoveAngleFunction(lua_State *L)
{
    lua_register(L, "moveAngle", luaFunc_moveAngle);
}