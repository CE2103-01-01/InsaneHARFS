cmake_minimum_required(VERSION 3.2)
project(harfs-disk)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#HARFS DISK
set(HARFS_DISK_FILES sourceCode/disk/harfs-disk-main.cpp
            sourceCode/disk/config/diskConfiguration.cpp
            libs/practicalsocket/PracticalSocket.cpp
            sourceCode/disk/proofs/FileManagerProof.cpp
            sourceCode/disk/managers/FileManager.cpp
            sourceCode/disk/managers/BlockManager.cpp
            sourceCode/disk/pathConstants.cpp
            sourceCode/disk/proofs/BlockManagerProof.cpp
            sourceCode/disk/managers/RegisterManager.cpp
            sourceCode/disk/models/Pointer.cpp
            sourceCode/disk/dataStructuresOnHD/List.cpp
            sourceCode/disk/dataStructuresOnHD/BTree.cpp)

add_executable(harfs-disk ${HARFS_DISK_FILES} sourceCode/disk/dataStructuresOnHD/Buffer.cpp sourceCode/disk/dataStructuresOnHD/Buffer.h)

set_target_properties(harfs-disk PROPERTIES COMPILE_FLAGS -pthread LINK_FLAGS -pthread)



#HARFS CONTROLLER
project(harfs-controller)

set(HARFS_CONTROLLER_FILES  sourceCode/controller/harfs-controller-main.cpp
                            libs/practicalsocket/PracticalSocket.cpp
                            sourceCode/controller/config/controllerConfiguration.cpp
                            sourceCode/controller/network/TCPServer.cpp)

add_executable(harfs-controller ${HARFS_CONTROLLER_FILES} )
set_target_properties(harfs-controller PROPERTIES COMPILE_FLAGS -pthread LINK_FLAGS -pthread)



#HARFS CLIENT
project(harfs-client)

set(HARFS_CLIENT_FILES  sourceCode/client/harfs-client-main.cpp
                        libs/practicalsocket/PracticalSocket.cpp
                        sourceCode/client/config/clientConfiguration.cpp
                        )

add_executable(harfs-client ${HARFS_CLIENT_FILES} sourceCode/client/network/TCPClient.cpp sourceCode/client/network/TCPClient.h)
set_target_properties(harfs-client PROPERTIES COMPILE_FLAGS -pthread LINK_FLAGS -pthread)
#RESOURCES

configure_file( res/disk_config.cfg res/disk_config.cfg COPYONLY)
configure_file( res/controller_config.cfg res/controller_config.cfg COPYONLY)
configure_file( res/client_config.cfg res/client_config.cfg COPYONLY)