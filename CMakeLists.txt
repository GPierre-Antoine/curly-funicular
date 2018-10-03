cmake_minimum_required(VERSION 3.11)
project(curly_funicular)

set(CMAKE_CXX_FLAGS "-O3 -W -Wall -Wextra --pedantic -Wno-comment -Werror")
set(CMAKE_CXX_STANDARD 14)

add_executable(kobe kobe/kobe.cpp)

add_executable(test_ncurses test_curses/main.cpp)
target_link_libraries(test_ncurses ncurses)

add_executable(pgtest postgresql/main.cpp)
target_link_libraries(pgtest pqxx)