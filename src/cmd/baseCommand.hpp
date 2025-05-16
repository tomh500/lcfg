#include "../utils.hpp"

// clang-format off
// Base Command Register
#define baseCommandFunction(cmd)                                                              \
    int luaFunc_##cmd(lua_State *L)                                                           \
    {                                                                                         \
        int argNum = lua_gettop(L);                                                           \
        int opt = 1;                                                                          \
        if (argNum == 1)                                                                      \
            opt = luaL_checkinteger(L, 1);                                                    \
        if (argNum > 1)                                                                       \
            luaL_error(L, format("Function '{}' expects 0 or 1 argument(s).", #cmd).c_str()); \
        log(format("receive {}({})", #cmd, opt));                                             \
        event.pushEvent(format("{} {} 0 0", #cmd, opt));                                      \
        return 0;                                                                             \
    }

// Base Command List 
#define baseCommandList \
    X(forward)\
    X(back)\
    X(right)\
    X(left)\
    X(duck)\
    X(attack)\
    X(attack2)\
    X(sprint)\
    X(lookatweapon)

#define X(cmd) baseCommandFunction(cmd)
baseCommandList
#undef X

// clang-format on
void registerLuaBaseFunctions(lua_State *L){
    #define X(cmd) lua_register(L, #cmd, luaFunc_##cmd);
        baseCommandList
    #undef X
}