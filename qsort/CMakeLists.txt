cmake_minimum_required(VERSION 3.14.5)
project(qsort)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE ${PROJECT_SOURCE_DIR}/src/main.cpp)
add_executable(qsort ${SOURCE})