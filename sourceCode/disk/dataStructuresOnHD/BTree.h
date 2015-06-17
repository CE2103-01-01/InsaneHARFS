//
// Created by roberto on 14/06/15.
//

#ifndef HARFS_CLIENT_BTREE_H
#define HARFS_CLIENT_BTREE_H

#include "../managers/FileManager.h"

#define DEFAULT_ORDER 100
#define DEFAULT_KEY_LENGHT 8
#define DEFAULT_NAME "tr"

#define HEADER_LENGHT 25
#define HEADER_OFFSET 8
#define ORDER_ON_HEADER 0
#define LENGHT_ON_HEADER 1
#define FIRST_EMPTY_ON_HEADER 2
#define KEY_LENGHT_ON_HEADER 3

#define NODE_OFFSET 24
#define NODE_ELEMENT_LENGHT 8
#define FATHER_ON_NODE 0
#define TERMINAL_ON_NODE 1
#define LAST_KEY 2


/**HEADER: | ORDEN 8 BYTES | LONGITUD 8 BYTES | PRIMER VACIO 8 BYTES | LONGITUD DE CLAVE 1 BYTE |*/

/**NODO:   | PADRE 8 BYTES | TERMINAL 8 BYTES | ULTIMA CLAVE 8 BYTES | PUNTERO 8 BYTES | CLAVE N BYTES | PUNTERO 8 BYTES |*/


class BTree {
    std::string headerPath;
    std::string dataPath;
    int order;
    long lenght;
    long firstEmpty;
    unsigned char keyLenght;
    void readHeader();
    void init(std::string);
    void updateHeader();
    public:
        BTree();
        BTree(std::string,long,long);
        BTree(long,long);
        BTree(std::string,std::string);
        void insertKey(void*,long);
        long searchKey(void*);
        void deleteKey(void*);
};

#endif //HARFS_CLIENT_BTREE_H