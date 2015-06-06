cmake_minimum_required(VERSION 3.2)
project(harfs-disk)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
                 sourceCode/handlers/FileManager.cpp
                 sourceCode/config/Configuration.cpp
                 sourceCode/dataStructures/proof.cpp
                 sourceCode/dataStructuresOnHD/List.cpp
                 sourceCode/models/Pointer.cpp
                 sourceCode/models/BlockManager.cpp
                 sourceCode/pathConstants.cpp)

configure_file( res/config.cfg res/config.cfg COPYONLY)


add_executable(harfs-disk ${SOURCE_FILES})

target_link_libraries (harfs-disk ${CMAKE_THREAD_LIBS_INIT})