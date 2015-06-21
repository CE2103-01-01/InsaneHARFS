//
// Created by roberto on 20/06/15.
//

#include "StorageBlockManager.h"

StorageBlockManager::StorageBlockManager(){
    mutex = static_cast<pthread_mutex_t*>(malloc(sizeof(pthread_mutex_t)));
    pthread_mutex_init(mutex,NULL);
    if(!fopen((PathConstants::PROJECT_PATH + HEADER_NAME).c_str(), static_cast<const char*>('r'))){
        FileManager::createFile(HEADER_NAME,BLOCK_NAME_LENGHT);
    }
    Buffer* tmp= FileManager::readFile(PathConstants::PROJECT_PATH+HEADER_NAME, 0, NUMBER_OF_BLOCKS_LENGHT);
    lenght = *static_cast<int*>(tmp->get(0));
    free(tmp);
    storageBlocks = FileManager::readFile(PathConstants::PROJECT_PATH+HEADER_NAME, 0, lenght*BLOCK_NAME_LENGHT+NUMBER_OF_BLOCKS_LENGHT);
}

StorageBlockManager::~StorageBlockManager(){
    free(storageBlocks);
}

void StorageBlockManager::updateHeader(){
    FileManager::writeFile(std::addressof(lenght),(PathConstants::PROJECT_PATH+HEADER_NAME).c_str(),0,sizeof(lenght));
}

static StorageBlockManager* StorageBlockManager::getInstance(){
    if(manager) return manager;
    else{
        manager = static_cast<StorageBlockManager*>(malloc(sizeof(StorageBlockManager)));
        new(manager) StorageBlockManager();
        return manager;
    }
}

int StorageBlockManager::addStorageBlocks(void* storageName){
    pthread_mutex_lock(mutex);
    FileManager::writeFile(std::addressof(lenght),HEADER_NAME,0,sizeof(lenght));
    lenght++;
    updateHeader();
    free(storageBlocks);
    storageBlocks = FileManager::readFile(PathConstants::PROJECT_PATH+HEADER_NAME, 0, lenght*BLOCK_NAME_LENGHT+NUMBER_OF_BLOCKS_LENGHT);
    pthread_mutex_unlock(mutex);
}