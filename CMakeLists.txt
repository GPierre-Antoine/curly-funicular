cmake_minimum_required(VERSION 3.11)
project(curly_funicular)

set(CMAKE_CXX_FLAGS "-O3 -W -Wall -Wextra --pedantic -Wno-comment -Werror")
set(CMAKE_CXX_STANDARD 14)

add_executable(kobe kobe/kobe.cpp test_ssh/networking/internal/ssh_options.h)

add_executable(test_ncurses test_curses/main.cpp)
target_link_libraries(test_ncurses ncurses)

add_executable(wrap_socket wrap_socket/main.cpp wrap_socket/networking/socket.cpp wrap_socket/networking/socket.h networking/networking_error.h networking/networking_error.cpp wrap_socket/networking/socket_factory.cpp wrap_socket/networking/socket_factory.h wrap_socket/networking/internal/socket_option.cpp wrap_socket/networking/internal/socket_option.h)

add_executable(pgtest postgresql/main.cpp)
target_link_libraries(pgtest pqxx)

add_executable(test_ssh test_ssh/main.cpp test_ssh/networking/ssh.cpp test_ssh/networking/ssh.h networking/networking_error.h networking/networking_error.cpp)
target_link_libraries(test_ssh ssh)


add_executable(revisions revisions/main.cpp revisions/main.cpp)