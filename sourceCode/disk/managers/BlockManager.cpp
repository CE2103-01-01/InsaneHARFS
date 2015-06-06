//
// Created by roberto on 05/06/15.
//

#include "BlockManager.h"

/**@brief elimina un registro y los registros anexos al mismo
 * @param long offset: numero de registro (posicion)
 */
BlockManager::BlockManager(std::string pathParam, int numberOfBlocksParam){
    numberOfBlocks = numberOfBlocksParam;
    firstEmptyBlock = 0;
    usedBlocks = 0;
    path = pathParam;
    std::fstream file(path.c_str(),std::ios::binary);
    FileManager::writeFile(static_cast<void*>(&firstEmptyBlock), path, FIRST_EMPTY_POSITION*BLOCK_MANAGER_COMPONENT_LENGHT, BLOCK_MANAGER_COMPONENT_LENGHT);
    FileManager::writeFile(static_cast<void*>(&usedBlocks), path, USED_POSITION*BLOCK_MANAGER_COMPONENT_LENGHT, BLOCK_MANAGER_COMPONENT_LENGHT);
    FileManager::writeFile(static_cast<void*>(&numberOfBlocksParam), path, MAX_BLOCKS_POSITION*BLOCK_MANAGER_COMPONENT_LENGHT, BLOCK_MANAGER_COMPONENT_LENGHT);
    int flag=-1;
    int tmp;
    for(int i = 0; i < numberOfBlocks ; i++){
        if(i<numberOfBlocksParam-1) tmp = i+1;
        else tmp = flag;
        FileManager::writeFile(static_cast<void*>(&tmp), path, BLOCK_MANAGER_HEADER_LENGHT + i*BLOCK_LENGHT+NEXT_LENGHT,
                               NEXT_EMPTY_LENGHT);
        FileManager::writeFile(static_cast<void*>(&flag), path, BLOCK_MANAGER_HEADER_LENGHT + i*BLOCK_LENGHT+NEXT_LENGHT,
                               NEXT_EMPTY_LENGHT);
    }
    file.close();
}

/**@brief agrega un nuevo registro
 * @param void* data: contenido
 * @param long size: tamano
 */
long BlockManager::addBlock(char* data, long dataSize){
    //toma el id
    int id = firstEmptyBlock;
    int flag = -1;
    //toma el id
    int tmp;
    for(int i = 0; i < dataSize/BLOCK_LENGHT + 1; i++){
        //toma el id
        tmp = firstEmptyBlock;
        //Escribe el dato, suma porque:  | siguiente | siguiente vacio | dato
        FileManager::writeFile(data+i*DATA_LENGHT, path, BLOCK_MANAGER_HEADER_LENGHT+firstEmptyBlock*BLOCK_LENGHT
                                                         +NEXT_LENGHT+NEXT_EMPTY_LENGHT, BLOCK_LENGHT);
        //Toma el nuevo primer ultimo, suma porque:  | siguiente | siguiente vacio | dato
        FileManager::readFile(static_cast<void*>(&firstEmptyBlock), path, BLOCK_MANAGER_HEADER_LENGHT
                                                                          + firstEmptyBlock*BLOCK_LENGHT+NEXT_LENGHT,
                              NEXT_EMPTY_LENGHT);
        //Escribe el siguiente vacio en -1, suma porque:  | siguiente | siguiente vacio | dato
        FileManager::writeFile(static_cast<void*>(&flag), path, BLOCK_MANAGER_HEADER_LENGHT+tmp*BLOCK_LENGHT+NEXT_LENGHT,
                               NEXT_EMPTY_LENGHT);
        if(i < dataSize/BLOCK_LENGHT) {
            //Si no es la ultima iteracion agrega siguiente, suma porque:  | siguiente | siguiente vacio | dato
            FileManager::writeFile(static_cast<void*>(&firstEmptyBlock), path, BLOCK_MANAGER_HEADER_LENGHT+tmp*BLOCK_LENGHT,
                                   NEXT_LENGHT);
        }
    }
    return id;
}

/**@brief busca un registro
 * @param long offset: numero de registro (posicion)
 * @return void*: dato del registro junto con los anexos
 */
void* BlockManager::searchBlock(int id){
    void* toRet = malloc(DATA_LENGHT);
    FileManager::readFile(toRet,path,BLOCK_MANAGER_HEADER_LENGHT+id*BLOCK_LENGHT,DATA_LENGHT);
    return toRet;
}

/**@brief elimina un registro y los registros anexos al mismo
 * @param long offset: numero de registro (posicion)
 */
void BlockManager::deleteBlock(int id){
    //Escribe el primer vacio como siguiente vacio y actualiza primer vacio
    FileManager::writeFile(static_cast<void*>(&firstEmptyBlock), path,
                           id*BLOCK_LENGHT + BLOCK_MANAGER_HEADER_LENGHT + NEXT_LENGHT, NEXT_EMPTY_LENGHT);
    firstEmptyBlock = id;
    //Se lee el siguiente
    int* next = static_cast<int*>(malloc(DATA_LENGHT));
    FileManager::readFile(next,path,id*BLOCK_LENGHT + BLOCK_MANAGER_HEADER_LENGHT,DATA_LENGHT);
    //si el siguiente no es -1 lo borra, ya que -1 indica que es el ultimo bloque de la cadena
    if(*next!=-1) {
        deleteBlock(*next);
        int tmp = -1;
        FileManager::writeFile(static_cast<void*>(&tmp), path, id*BLOCK_LENGHT + BLOCK_MANAGER_HEADER_LENGHT,
                               NEXT_LENGHT);
    }
}