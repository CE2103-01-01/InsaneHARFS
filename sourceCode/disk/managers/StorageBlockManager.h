//
// Created by roberto on 20/06/15.
//

#ifndef HARFS_CLIENT_STORAGEBLOCKMANAGER_H
#define HARFS_CLIENT_STORAGEBLOCKMANAGER_H

#include "../pathConstants.h"
#include "../dataStructuresOnHD/Buffer.h"
#include "FileManager.h"

#define HEADER_NAME "storage.blocks"
#define BLOCK_NAME_LENGHT 128
#define NUMBER_OF_BLOCKS_LENGHT 4

//HEADER: | Cantidad 4B | Nombre 128B | Nombre 128B |...

class StorageBlockManager {
    pthread_mutex_t* mutex;
    int lenght;
    Buffer* storageBlocks;
    static StorageBlockManager* manager;
    StorageBlockManager();
    ~StorageBlockManager();
    void updateHeader();
public:
    static StorageBlockManager* getInstance();
    int addStorageBlocks(void*);

};


#endif //HARFS_CLIENT_STORAGEBLOCKMANAGER_H
