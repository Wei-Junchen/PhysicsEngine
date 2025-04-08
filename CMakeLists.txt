cmake_minimum_required(VERSION 3.22)

project(PhysicsEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC)

message("##Source files: ${SRC}")

include_directories(${CMAKE_SOURCE_DIR}/inc)

#构建项目
add_executable(PhysicsEngine ${CMAKE_SOURCE_DIR}/main.cpp ${SRC})