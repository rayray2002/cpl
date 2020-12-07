cmake_minimum_required(VERSION 3.17)
project(class_preview)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(SDL_DIR /usr/local/Cellar/sdl2/2.0.12_1/) # 这个SDL开发包的路径，可以通过brew info sdl2查出来
include_directories(${SDL_DIR}/include/) # 添加SDL头文件搜索路径
link_directories(${SDL_DIR}/lib/) # 增加SDL链接库目录

add_executable(p7 p7.cpp)
add_executable(p10-11 p10-11.cpp)
add_executable(p12 p12.cpp)
add_executable(p21 p21.cpp SDL_bgi.cpp)

target_link_libraries(p21 SDL2 SDL2_test SDL2main)