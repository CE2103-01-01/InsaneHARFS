cmake_minimum_required(VERSION 3.2)
project(harfs-disk)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(DATA_STRUCTURES Code/DataStructures/proof.cpp)

set(MODELS)  #TODO revisar: Code/models/FileManager.cpp

set(SOURCE_FILES    Code/main.cpp)

add_executable(harfs-disk ${SOURCE_FILES} ${DATA_STRUCTURES} ${MODELS} )