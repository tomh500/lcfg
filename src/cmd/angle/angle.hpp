#include "../../utils.hpp"
#include "angleUtils.hpp"

int luaFunc_angle(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 2)
        luaL_error(L, "Function 'angle' expects 2 arguments.");
    
    double yaw=luaL_checknumber(L,2);
    double pitch=luaL_checknumber(L,1);
    ANGLE::relativeAngle(yaw,pitch);
    event.sleep(1);
    ANGLE::useUserSensitivity();
    return 0;
}

void registerLuaAngleFunction(lua_State *L)
{
    lua_register(L, "angle", luaFunc_angle);
}