//
// Created by roberto on 05/06/15.
//

#ifndef HARFS_DISK_LIST_H
#define HARFS_DISK_LIST_H

#include <string>
#include <fstream>
#include "../managers/FileManager.h"

// HEADER:  | HEAD 4 BYTES | TAIL 4 BYTES | DATA SIZE 4 BYTES | KEY SIZE 4 BYTES | FIRST EMPTY 4 BYTES | LENGHT 4 BYTES | = 24 BYTES
#define LIST_HEADER_LENGHT 20
#define LIST_HEADER_MEMBER_LENGHT 4
#define POSITION_OF_HEAD_ON_HEADER 0
#define POSITION_OF_TAIL_ON_HEADER 1
#define POSITION_OF_DATA_SIZE_ON_HEADER 2
#define POSITION_OF_KEY_SIZE_ON_HEADER 3
#define POSITION_OF_FIRST_EMPTY_ON_HEADER 4
#define POSITION_OF_LENGHT_ON_HEADER 5

// NODES:   | NEXT 4 BYTES | PREVIOUS 4 BYTES | NEXT EMPTY 4 BYTES | KEY X BYTES | DATA N BYTES |   = 12 + X + N BYTES
#define LIST_NODE_MEMBER_LENGHT 4
#define LIST_NODE_LENGHT_WITHOUT_DATA 12
#define POSITION_OF_NEXT_ON_NODE 0
#define POSITION_OF_PREVIOUS_ON_NODE 1
#define POSITION_OF_NEXT_EMPTY_ON_NODE 2
#define POSITION_OF_KEY_ON_NODE 3
#define POSITION_OF_DATA_ON_NODE 4



class List {
    int head;
    int tail;
    int dataSize;
    int keySize;
    int firstEmpty;
    int lenght;
    std::string path;
    void updateHeader();
    bool compare(void*, void*, int);
    public:
        List(std::string, int, int);
        void* search(void*);
        void* search(int);
        int getOffset(void*);
        int insertData(void*, void*);
        void deleteData(void*);
};


#endif //HARFS_DISK_LIST_H
