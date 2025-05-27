#include "../../utils.hpp"

int luaFunc_lockMouse(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 0)
        luaL_error(L, "Function 'lockMouse' expects 0 argument.");
    event.pushEvent(SCFGProxy::LOCKMOUSE);
    return 0;
}
int luaFunc_unlockMouse(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 0)
        luaL_error(L, "Function 'unlockMouse' expects 0 argument.");
    event.pushEvent(SCFGProxy::UNLOCKMOUSE);
    return 0;
}
int luaFunc_wasdCancel(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 0)
        luaL_error(L, "Function 'wasdCancel' expects 0 argument.");
    event.pushEvent(SCFGProxy::WASDCANCEL);
    return 0;
}
int luaFunc_play(lua_State *L)
{
    int argNum = lua_gettop(L);
    if (argNum != 1)
        luaL_error(L, "Function 'play' expects 1 argument.");
    string s(luaL_checkstring(L, 1));
    if (s == "scfg::beep")
        s = "sounds/ui/beepclear.vsnd_c";
    if (s == "scfg::bad")
        s = "sounds/ui/lobby_notification_kicked";
    event.pushEvent(format("play {}", s));
    return 0;
}
void registerLuaMiscFunction(lua_State *L)
{
    lua_register(L, "lockMouse", luaFunc_lockMouse);
    lua_register(L, "unlockMouse", luaFunc_unlockMouse);
    lua_register(L, "wasdCancel", luaFunc_wasdCancel);
    lua_register(L, "play", luaFunc_play);
}