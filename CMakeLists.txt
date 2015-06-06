cmake_minimum_required(VERSION 3.2)
project(harfs-disk)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(HARFS_DISK_FILES sourceCode/mains/harfs-disk-main.cpp
            sourceCode/config/diskConfiguration.cpp
            sourceCode/managers/NetworkUtils.cpp
            libs/practicalsocket/PracticalSocket.cpp
            sourceCode/proofs/FileManagerProof.cpp
            sourceCode/managers/FileManager.cpp
            sourceCode/pathConstants.cpp
)




add_executable(harfs-disk ${HARFS_DISK_FILES})

target_link_libraries (harfs-disk ${CMAKE_THREAD_LIBS_INIT})

#HarfsController
project(harfs-controller)

set(HARFS_CONTROLLER_FILES
)

add_executable(harfs-controller ${HARFS_CONTROLLER_FILES} sourceCode/mains/harfs-controller-main.cpp
                                                            sourceCode/config/controllerConfiguration.cpp)


#RESOURCES

configure_file( res/disk_config.cfg res/disk_config.cfg COPYONLY)
configure_file( res/controller_config.cfg res/controller_config.cfg COPYONLY)