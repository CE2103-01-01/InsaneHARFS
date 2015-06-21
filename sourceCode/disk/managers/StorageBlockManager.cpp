//
// Created by roberto on 20/06/15.
//

#include "StorageBlockManager.h"

StorageBlockManager* StorageBlockManager::manager = 0;

StorageBlockManager::StorageBlockManager(){
    metadata = static_cast<List*>(malloc(sizeof(List)));
    new(metadata) List();
    blocks = static_cast<BlockManager*>(malloc(sizeof(BlockManager)));
    new(blocks) BlockManager();
    mutex = static_cast<pthread_mutex_t*>(malloc(sizeof(pthread_mutex_t)));
    pthread_mutex_init(mutex,NULL);
    if(!fopen((PathConstants::PROJECT_PATH + HEADER_NAME).c_str(), "r")){
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

StorageBlockManager* StorageBlockManager::getInstance(){
    if(manager) return manager;
    else{
        manager = static_cast<StorageBlockManager*>(malloc(sizeof(StorageBlockManager)));
        new(manager) StorageBlockManager();
        return manager;
    }
}

bool StorageBlockManager::addStorageBlocks(void* storageName, void* data){
    char* tmp = static_cast<char*>(storageName);
    int sizeOfVoid = *static_cast<int*>(data);
    int keyOffset = *static_cast<int*>(data+4);
    int keySize = *static_cast<int*>((keyOffset+1)*4);
    std::string tmpPath = "";
    for(int i = 0; i<BLOCK_NAME_LENGHT && (tmp+i)!="."; i++) tmpPath.append(tmp+i);
    pthread_mutex_lock(mutex);
    FileManager::writeFile(std::addressof(lenght),PathConstants::PROJECT_PATH+HEADER_NAME,0,sizeof(lenght));
    FileManager::writeFile(storageName,PathConstants::PROJECT_PATH+HEADER_NAME,lenght*32 + 4,sizeOfVoid);
    new (metadata) List(tmpPath,8,keySize);
    lenght++;
    updateHeader();
    free(storageBlocks);
    storageBlocks = FileManager::readFile(PathConstants::PROJECT_PATH+HEADER_NAME, 0, lenght*BLOCK_NAME_LENGHT+NUMBER_OF_BLOCKS_LENGHT);
    pthread_mutex_unlock(mutex);
    return true;
}

bool StorageBlockManager::addRegister(void* data, long size, int storageBlock){
    char* tmp = static_cast<char*>(storageBlocks->get(NUMBER_OF_BLOCKS_LENGHT+(storageBlock-1)*storageBlock));
    if(storageBlock<=lenght && tmp==0){
        std::string tmpPath = "";
        for(int i = 0; i<BLOCK_NAME_LENGHT && (tmp+i)!="."; i++) tmpPath.append(tmp+i);
        blocks->changeStorageBlock(tmpPath + STORAGE_BLOCKS_EXT);
        long offset = blocks->addBlock(data,size);
        metadata->changePath(tmpPath + LIST_EXT);
        metadata->insertData(data,std::addressof(offset));
        return true;
    }else{
        return false;
    }
}

bool StorageBlockManager::deleteRegister(void* key, int storageBlock){
    char* tmp = static_cast<char*>(storageBlocks->get(NUMBER_OF_BLOCKS_LENGHT+(storageBlock-1)*storageBlock));
    if(storageBlock<=lenght && tmp==0){
        std::string tmpPath = "";
        for(int i = 0; i<BLOCK_NAME_LENGHT && (tmp+i)!="."; i++) tmpPath.append(tmp+i);
        blocks->changeStorageBlock(tmpPath + STORAGE_BLOCKS_EXT);
        long offset = metadata->getOffset(key);
        metadata->changePath(tmpPath + LIST_EXT);
        metadata->deleteData(key);
        return true;
    }else{
        return false;
    }
}