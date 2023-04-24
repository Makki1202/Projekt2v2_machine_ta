cmake_minimum_required(VERSION 3.16)
project(Projekt2v2_machine_ta C)

set(CMAKE_C_STANDARD 99)

add_executable(Projekt2v2_machine_ta main.c cmake-build-debug/game.c cmake-build-debug/game.h cmake-build-debug/IO.c cmake-build-debug/IO.h cmake-build-debug/linkedLists.c cmake-build-debug/linkedLists.h)
