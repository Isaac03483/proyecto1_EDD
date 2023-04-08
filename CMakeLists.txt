cmake_minimum_required(VERSION 3.24)
project(proyecto1_EDD)

set(CMAKE_CXX_STANDARD 17)

add_executable(proyecto1_EDD main.cpp Cancion.h Playlist.h)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(proyecto1_EDD  ${SDL2_LIBRARIES})

