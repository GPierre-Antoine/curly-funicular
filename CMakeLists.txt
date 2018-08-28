cmake_minimum_required(VERSION 3.12)
project(curly_funicular)

set(CMAKE_CXX_FLAGS "-O3 -W -Wall -Wextra --pedantic -Wno-comment -Werror")
set(CMAKE_CXX_STANDARD 17)

add_executable(kobe.out runKobeChance/main.cpp)
