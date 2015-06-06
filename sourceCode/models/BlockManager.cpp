//
// Created by roberto on 05/06/15.
//

#include "BlockManager.h"

/**@brief elimina un registro y los registros anexos al mismo
 * @param long offset: numero de registro (posicion)
 */
BlockManager::BlockManager(std::string pathParam, long numberOfBlocksParam){
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
long BlockManager::addBlock(char* data, long size){

}

/**@brief busca un registro
 * @param long offset: numero de registro (posicion)
 * @return void*: dato del registro junto con los anexos
 */
void* BlockManager::searchBlock(long offset){

}

/**@brief elimina un registro y los registros anexos al mismo
 * @param long offset: numero de registro (posicion)
 */
void BlockManager::deleteBlock(long offset){

}