#include "../../utils.hpp"
#include "angleUtils.hpp"

int luaFunc_setAngle(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 2)
        luaL_error(L, "Function 'setAngle' expects 2 arguments.");
    
    double yaw=luaL_checknumber(L,2);
    double pitch=luaL_checknumber(L,1);
    ANGLE::resetAngle();
    event.sleep(1);
    ANGLE::relativeAngle(yaw,pitch);
    event.sleep(1);
    ANGLE::useUserSensitivity();
    return 0;
}

void registerLuaSetAngleFunction(lua_State *L)
{
    lua_register(L, "setAngle", luaFunc_setAngle);
}