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
    for(int i = 0; i < BLOCK_MANAGER_HEADER_LENGHT + numberOfBlocks*BLOCK_LENGHT ; i++){
        file.write(0,1);
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
        FileManager::writeFile(data, path, firstEmptyBlock+NEXT_LENGHT+NEXT_EMPTY_LENGHT, BLOCK_LENGHT);
        //Toma el nuevo primer ultimo, suma porque:  | siguiente | siguiente vacio | dato
//        FileManager::readFile(static_cast<char*>(&firstEmptyBlock), path, firstEmptyBlock+NEXT_LENGHT, NEXT_EMPTY_LENGHT);
        //Escribe el siguiente vacio en -1, suma porque:  | siguiente | siguiente vacio | dato
//        FileManager::writeFile(static_cast<char*>(&flag), path, tmp+NEXT_LENGHT, NEXT_EMPTY_LENGHT);
        if(i < dataSize/BLOCK_LENGHT) {
            //Si no es la ultima iteracion agrega siguiente, suma porque:  | siguiente | siguiente vacio | dato
//            FileManager::writeFile(static_cast<char*>(&firstEmptyBlock), path, tmp, NEXT_LENGHT);
        }
    }
    return id;
}

/**@brief busca un registro
 * @param long offset: numero de registro (posicion)
 * @return void*: dato del registro junto con los anexos
 */
void* BlockManager::searchBlock(int id){

}

/**@brief elimina un registro y los registros anexos al mismo
 * @param long offset: numero de registro (posicion)
 */
void BlockManager::deleteBlock(int id){

}