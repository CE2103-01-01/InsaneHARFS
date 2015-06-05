//
// Created by roberto on 05/06/15.
//

#ifndef HARFS_DISK_LIST_H
#define HARFS_DISK_LIST_H

#include <string>
#include <fstream>
#include "../models/Pointer.h"

#define NODE_LENGHT 16
#define HEADER_LENGHT 16

// HEADER:  |  FIRST EMPTY 8 BYTES  |     TAIL 8 BYTES     |    = 16 BYTES
// NODES:   |  DATA OFFSET 8 BYTES  |  NEXT EMPTY 8 BYTES  |    = 16 BYTES
// El data offset es un numero que indica la posicion en otro archivo. Se debera coordinar mediante manager.
class List {
    long firstEmpty;
    long tail;
    std::string path;
    public:
        List(std::string);
        Pointer search(Pointer);
        void insertData(Pointer);
        void deleteData(Pointer);
};


#endif //HARFS_DISK_LIST_H
