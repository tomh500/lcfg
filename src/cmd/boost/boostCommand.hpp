#include "../../utils.hpp"

namespace BOOST
{
    int ty = 0;
    void stop()
    {
        if (ty < 0)
            event.pushEvent("-left"), event.pushEvent("-turnleft");
        if (ty > 0)
            event.pushEvent("-right"), event.pushEvent("-turnright");
        ty = 0;
    }
    void left(double val)
    {
        if (ty != 0)
            stop();
        event.pushEvent("+left");
        event.pushEvent(format("turnleft {:6f} 0 0", val / max_yaw_speed));
        ty = -1;
    }
    void right(double val)
    {
        if (ty != 0)
            stop();
        event.pushEvent("+right");
        event.pushEvent(format("turnright {:6f} 0 0", val / max_yaw_speed));
        ty = 1;
    }
}

int luaFunc_boostLeft(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 1)
        luaL_error(L, "Function 'boostLeft' expects 1 argument.");
    double val = luaL_checknumber(L, 1);
    if (val <= 0 || val > 300)
    {
        luaL_error(L, "boost speed must be in (0,300]!");
    }
    BOOST::left(val);
    return 0;
}
int luaFunc_boostRight(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 1)
        luaL_error(L, "Function 'boostRight' expects 1 argument.");
    double val = luaL_checknumber(L, 1);
    if (val <= 0 || val > 300)
    {
        luaL_error(L, "boost speed must be in (0,300]!");
    }
    BOOST::right(val);
    return 0;
}
int luaFunc_boostStop(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 0)
        luaL_error(L, "Function 'boostStop' expects 0 argument.");
    if (BOOST::ty == 0)
    {
        lua_warning(L, "you are using 'boostStop' without 'boostLeft' or 'boostRight'. Are you sure?", 0);
    }
    BOOST::stop();
    return 0;
}
void registerLuaBoostFunction(lua_State *L)
{
    lua_register(L, "boostLeft", luaFunc_boostLeft);
    lua_register(L, "boostRight", luaFunc_boostRight);
    lua_register(L, "boostStop", luaFunc_boostStop);
}