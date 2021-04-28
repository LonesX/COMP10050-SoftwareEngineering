cmake_minimum_required(VERSION 3.17)
project(Project_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Project_2 src/main.c src/interface.c src/moves.c lib/main.h src/player.c lib/player.h)
