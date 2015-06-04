cmake_minimum_required(VERSION 3.2)
project(harfs-disk)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
                models/Pointer.h)
add_executable(harfs-disk ${SOURCE_FILES} models/FileManager.cpp models/FileManager.h Data/DoubleList.h)