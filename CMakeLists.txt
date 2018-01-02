cmake_minimum_required(VERSION 3.0)
project(solext)

set (CMAKE_CXX_STANDARD 14)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

option(SOLEXT_SYSTEM_LUA "Use system lua" off)
option(SOLEXT_BIN "compile binary" on)


if (NOT ${SOLEXT_SYSTEM_LUA})
    message(STATUS "Using local lua")
    include(cmake/lua.cmake)
    set(LUA_INCLUDE_DIR vendor/lua)
    set(LUA_LIBDIR ${CMAKE_CURRENT_BINARY_DIR})
    set(LUA_LIBRARIES lua m)
else()
    message(STATUS "Using system libuv")
    find_package(PkgConfig)
    pkg_search_module(LUA REQUIRED lua)
endif (NOT ${SOLEXT_SYSTEM_LUA})

## SOL
include_directories(${LUA_INCLUDEDIR})
link_directories(${LUA_LIBDIR})
include_directories(vendor/sol2/single)

## CSYSTEM
option(CS_BUILD_CXX "build cxx version" on)
include_directories(vendor/csystem/include)
add_subdirectory(vendor/csystem)

include_directories(include)
add_subdirectory(src)

if(SOLEXT_BIN)
    add_subdirectory(example)
endif(SOLEXT_BIN)