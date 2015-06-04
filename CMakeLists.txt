cmake_minimum_required(VERSION 3.2)
project(harfs-disk)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(HEADER_FILES Code/models/pointer/Pointer.h
                 Code/models/pointer/MemoryPointer.h
                 Code/DataStructures/DoubleLinkedNode.h
                 Code/DataStructures/DoubleLinkedList.h
                 Code/DataStructures/BinaryTree.h)

set(SOURCE_FILES Code/main.cpp
                 Code/models/pointer/MemoryPointer.tpp)

add_executable(harfs-disk ${SOURCE_FILES} ${HEADER_FILES} Code/DataStructures/proof.h Code/DataStructures/proof.cpp)