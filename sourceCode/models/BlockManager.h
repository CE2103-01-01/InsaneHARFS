//
// Created by roberto on 05/06/15.
//

#ifndef HARFS_DISK_REGISTERMANAGER_H
#define HARFS_DISK_REGISTERMANAGER_H

#include <fstream>

// HEADER:      |    PrimerVacio  4 Bytes   |        Usados 4 Bytes         |   Blouqes totales 4 Bytes  | =  12 Bytes

#define BLOCK_MANAGER_HEADER_LENGHT 24
#define BLOCK_MANAGER_COMPONENT_LENGHT 4
#define FIRST_EMPTY_POSITION 0
#define USED_POSITION 1
#define MAX_BLOCKS_POSITION 2

// BLOQUES:     |     Siguiente  4 Bytes    |    Siguiente Vacio 4 Bytes    |       Dato  512 Bytes      | =  520 Bytes

#define BLOCK_LENGHT 520
#define NEXT_LENGHT 4
#define NEXT_EMPTY_LENGHT 4
#define DATA_LENGHT 512
#define NEXT_POSITION 0
#define NEXT_EMPTY_POSITION 1
#define DATA_POSITION 2

class BlockManager {
    std::string path;
    long firstEmptyBlock;
    long usedBlocks;
    long numberOfBlocks;
    public:
        BlockManager(std::string, long);
        long addBlock(char*, long);
        void* searchBlock(long);
        void deleteBlock(long);
};

#endif //HARFS_DISK_REGISTERMANAGER_H
