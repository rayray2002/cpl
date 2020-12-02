cmake_minimum_required(VERSION 3.17)
project(hw01)

set(CMAKE_CXX_STANDARD 14)

add_executable(1 "日期轉換 .cpp")
add_executable(2  "矩陣投影 .cpp")
add_executable(3 圈圈叉叉.cpp)
add_executable(4 簡易函數繪圖器.cpp)
add_executable(5  "IEEE 754 半精度浮點數 .cpp")
add_executable(6 有點重疊的圖片.cpp)

add_executable(5_test "IEEE 754 半精度浮點數2.cpp")
add_executable(temp temp.cpp)
add_executable(maze 走迷宮.cpp)
add_executable(change 找錢.cpp)
add_executable(bintodec bintodec.cpp)