cmake_minimum_required(VERSION 3.30)
# cmakelist collision exe
set(NAME_OF_PROJECT collision)

add_executable(${NAME_OF_PROJECT} collision.cpp)

target_link_libraries(${NAME_OF_PROJECT} PRIVATE collision_src)