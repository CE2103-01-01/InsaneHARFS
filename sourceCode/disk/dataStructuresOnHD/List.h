//
// Created by roberto on 05/06/15.
//

#ifndef HARFS_DISK_LIST_H
#define HARFS_DISK_LIST_H

#include <string>
#include <fstream>

#define NODE_LENGHT 16
#define LIST_HEADER_LENGHT 16

// HEADER:  |  FIRST EMPTY 8 BYTES  |     TAIL 8 BYTES     |    = 16 BYTES
// NODES:   |  DATA OFFSET 8 BYTES  |  NEXT EMPTY 8 BYTES  |    = 16 BYTES
// El data offset es un numero que indica la posicion en otro archivo. Se debera coordinar mediante manager.

class List {
    int firstEmpty;
    std::string path;
    public:
        List(std::string);
        void* search(int);
        void insertData(void*);
        void deleteData(int);
};


#endif //HARFS_DISK_LIST_H
