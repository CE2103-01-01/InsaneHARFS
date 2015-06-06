//
// Created by roberto on 05/06/15.
//

#ifndef HARFS_DISK_REGISTERMANAGER_H
#define HARFS_DISK_REGISTERMANAGER_H

#include <string>
#include <fstream>

// HEADER:      |    PrimerVacio  8 Bytes   |        Usados 8 Bytes         |   Blouqes totales 8 Bytes  | =  24 Bytes

#define BLOCK_MANAGER_HEADER_LENGHT 24
#define BLOCK_MANAGER_COMPONENT_LENGHT 8
#define FIRST_EMPTY_POSITION 0
#define USED_POSITION 1
#define MAX_BLOCKS_POSITION 2

// BLOQUES:     |     Siguiente  8 Bytes    |    Siguiente Vacio 8 Bytes    |       Dato  512 Bytes      | =  528 Bytes

#define BLOCK_LENGHT 528
#define NEXT_LENGHT 8
#define NEXT_EMPTY_LENGHT 8
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
