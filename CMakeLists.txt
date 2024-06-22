cmake_minimum_required(VERSION 3.28)
project(DOOM_Test)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

add_executable(DOOM_Test main.cpp
        src/Player.cpp
        src/Player.h
        src/Enemy.cpp
        src/Enemy.h
        src/Game.cpp
        src/Game.h
        src/Projectile.cpp
        src/Projectile.h)

target_link_libraries(DOOM_Test raylib)
