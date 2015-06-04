cmake_minimum_required(VERSION 3.2)
project(harfs-disk)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
                src/models/FileManager.cpp
                src/models/FileManager.h
                src/models/Pointer.h
                src/config/Configuration.cpp
                src/config/Configuration.h)

configure_file( res/config.cfg res/config.cfg COPYONLY)


add_executable(harfs-disk ${SOURCE_FILES} )

target_link_libraries (harfs-disk ${CMAKE_THREAD_LIBS_INIT})