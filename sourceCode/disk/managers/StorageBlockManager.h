//
// Created by roberto on 20/06/15.
//

#ifndef HARFS_CLIENT_STORAGEBLOCKMANAGER_H
#define HARFS_CLIENT_STORAGEBLOCKMANAGER_H
#include "../../../libs/rapidjson/document.h"
#include "../pathConstants.h"
#include "../dataStructuresOnHD/Buffer.h"
#include "FileManager.h"
#include "BlockManager.h"
#include "../dataStructuresOnHD/List.h"
#include "../network/JsonWriter.h"
#include "../network/TCPServer.h"

#define HEADER_NAME "storage.blocks"
#define BLOCK_NAME_LENGHT 32
#define NUMBER_OF_BLOCKS_LENGHT 4

#define CLIENTS_FILE "clients.md"
#define STORAGE_BLOCKS_EXT ".storage"
#define LIST_EXT ".list"

//USERS:  | Cantidad 4 B | Nombre 32 B | Clave 8 B | Nombre 32 B | Clave 8 B |...
//HEADER: | Cantidad 4 B | Nombre 128 B | Nombre 128 B |...

class StorageBlockManager {
    int users;
    int lenght;
    BlockManager* blocks;
    pthread_mutex_t* mutex;
    List* metadata;
    Buffer* storageBlocks;
    static StorageBlockManager* manager;
    StorageBlockManager();
    ~StorageBlockManager();
    void updateHeader();
public:
    static StorageBlockManager* getInstance();
    bool addStorageBlocks(void*,void*);
    bool addRegister(void*,long,int);
    bool deleteRegister(void*,int);
    void messageHandler(std::string);
    bool confirmUser(void*,void*);
};


#endif //HARFS_CLIENT_STORAGEBLOCKMANAGER_H
