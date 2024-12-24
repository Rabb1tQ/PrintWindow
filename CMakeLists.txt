cmake_minimum_required(VERSION 3.26)
project(PrintWindow)

set(CMAKE_CXX_STANDARD 17)

add_executable(PrintWindow main.cpp
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os")  # 开启最小化优化
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")  # 去除符号信息

find_package(tabulate CONFIG REQUIRED)
target_link_libraries(PrintWindow PRIVATE tabulate::tabulate)