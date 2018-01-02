cmake_minimum_required (VERSION 2.6)
project (lua)  # project here actually means solution in premake

if(WIN32)
        add_definitions( -D_CRT_SECURE_NO_WARNINGS )
endif()

set(LUA_PATH ${PROJECT_ROOT}/vendor/lua)

# 1. lua static library
# how to rename library name?
# add_library (lualib STATIC 
#         ${LUA_PATH}/lapi.c 
#         ${LUA_PATH}/lcode.c 
#         ${LUA_PATH}/lctype.c 
#         ${LUA_PATH}/ldebug.c 
#         ${LUA_PATH}/ldo.c 
#         ${LUA_PATH}/ldump.c 
#         ${LUA_PATH}/lfunc.c 
#         ${LUA_PATH}/lgc.c 
#         ${LUA_PATH}/llex.c 
#         ${LUA_PATH}/lmem.c 
#         ${LUA_PATH}/lobject.c 
#         ${LUA_PATH}/lopcodes.c 
#         ${LUA_PATH}/lparser.c 
#         ${LUA_PATH}/lstate.c 
#         ${LUA_PATH}/lstring.c 
#         ${LUA_PATH}/ltable.c 
#         ${LUA_PATH}/ltm.c 
#         ${LUA_PATH}/lundump.c 
#         ${LUA_PATH}/lvm.c 
#         ${LUA_PATH}/lzio.c 
#         ${LUA_PATH}/lauxlib.c 
#         ${LUA_PATH}/lbaselib.c 
#         ${LUA_PATH}/lbitlib.c 
#         ${LUA_PATH}/lcorolib.c 
#         ${LUA_PATH}/ldblib.c 
#         ${LUA_PATH}/liolib.c 
#         ${LUA_PATH}/lmathlib.c 
#         ${LUA_PATH}/loslib.c 
#         ${LUA_PATH}/lstrlib.c 
#         ${LUA_PATH}/ltablib.c 
#         ${LUA_PATH}/loadlib.c 
#         ${LUA_PATH}/linit.c
# )


file(GLOB_RECURSE LUA_SOURCES "${LUA_PATH}/*.c")
add_library(lualib ${LUA_SOURCES})
set_target_properties(lualib PROPERTIES OUTPUT_NAME "lua") # rename the library output name

# 2. lua interpreter
#link_directories (${LUA_BINARY_DIR})
#add_executable (lua lua.c)
#target_link_libraries (lua lualib)
#if(UNIX)
#        target_link_libraries( lua m )
#endif()

# 3. lua compiler
#link_directories (${LUA_BINARY_DIR})
#add_executable (luac luac.c)
#target_link_libraries (luac lualib)
#if(UNIX)
#        target_link_libraries( luac m )
#endif()