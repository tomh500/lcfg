#include "../utils.hpp"

// clang-format off
// Base Instant Command Register
#define baseInstantCommandFunction(cmd)                                                              \
    int luaFunc_##cmd(lua_State *L)                                                           \
    {                                                                                         \
        int argNum = lua_gettop(L);                                                           \
        if (argNum > 0)                                                                       \
            luaL_error(L, format("Function '{}' expects 0 or 1 argument(s).", #cmd).c_str()); \
        log(format("receive {}", #cmd));                                             \
        event.pushEvent(format("{}", #cmd));                                      \
        return 0;                                                                             \
    }

// Base Command List 
#define baseInstantCommandList \
    X(slot1)\
    X(slot2)\
    X(slot3)\
    X(slot4)\
    X(slot5)\
    X(slot6)\
    X(slot7)\
    X(slot8)\
    X(slot9)\
    X(slot10)\
    X(slot11)

#define X(cmd) baseInstantCommandFunction(cmd)
baseInstantCommandList
#undef X

void registerLuaBaseInstantFunctions(lua_State *L)
{
#define X(cmd) lua_register(L, #cmd, luaFunc_##cmd);
    baseInstantCommandList
#undef X
}

// clang-format on