cmake_minimum_required(VERSION 3.10.0)
project(Game VERSION 0.1.0 LANGUAGES C CXX)

if (MINGW)
    add_compile_options(-static-libgcc -static-libstdc++)
    add_link_options(-static -lpthread)	
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_options(-O3)
        add_link_options(-s)
    endif()
endif()

add_executable(Game main.cpp)