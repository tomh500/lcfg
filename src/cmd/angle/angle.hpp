#include "../../utils.hpp"
#include "angleUtils.hpp"

int luaFunc_angle(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 2)
        luaL_error(L, "Function 'angle' expects 2 arguments.");

    double yaw = luaL_checknumber(L, 2);
    double pitch = luaL_checknumber(L, 1);
    ANGLE::relativeAngle(yaw, pitch);
    event.sleep(1);
    ANGLE::useUserSensitivity();
    return 0;
}
int luaFunc_moveAngle(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 3)
        luaL_error(L, "Function 'moveAngle' expects 3 arguments.");

    double yaw = luaL_checknumber(L, 2);
    double pitch = luaL_checknumber(L, 1);
    int t = luaL_checkinteger(L, 3);

    ANGLE::moveAngle(yaw, pitch, t);
    return 0;
}
int luaFunc_setAngle(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 2)
        luaL_error(L, "Function 'setAngle' expects 2 arguments.");

    double yaw = luaL_checknumber(L, 2);
    double pitch = luaL_checknumber(L, 1);
    ANGLE::resetAngle();
    event.sleep(1);
    ANGLE::relativeAngle(yaw, pitch);
    event.sleep(1);
    ANGLE::useUserSensitivity();
    return 0;
}
int luaFunc_setExpectAngle(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 2)
        luaL_error(L, "Function 'setExpectAngle' expects 2 arguments.");

    double yaw = luaL_checknumber(L, 2);
    double pitch = luaL_checknumber(L, 1);
    ANGLE::lst_yaw = yaw;
    ANGLE::lst_pitch = pitch;
    return 0;
}

void registerLuaAngleFunction(lua_State *L)
{
    lua_register(L, "angle", luaFunc_angle);
    lua_register(L, "moveAngle", luaFunc_moveAngle);
    lua_register(L, "setAngle", luaFunc_setAngle);
    lua_register(L, "setExpectAngle", luaFunc_setExpectAngle);
}