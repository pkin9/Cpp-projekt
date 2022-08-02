cmake_minimum_required(VERSION 3.16)

project(ORBIT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Armadillo REQUIRED)

add_executable(orbit main.cpp orbit.cpp)
target_link_libraries(orbit ${ARMADILLO_LIBRARIES})
