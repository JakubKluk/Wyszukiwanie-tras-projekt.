cmake_minimum_required(VERSION 3.10)
project(Program_ciapongi)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)


set(SOURCE_FILES
        src/ciapong.cpp)

add_executable(Program_ciapongi main.cpp  src/ciapong.cpp include/ciapong.hpp src/test.cpp)
