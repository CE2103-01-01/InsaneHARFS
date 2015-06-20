//
// Created by roberto on 13/06/15.
//

#ifndef HARFS_CLIENT_BTREE_H
#define HARFS_CLIENT_BTREE_H

#include "BNode.h"

template <typename  DataType, typename  KeyType> class BTree{
    BNode* root;
    int order;
public:
    BTree(int);
    BTree(const BTree&);
    void operator =(const BTree&);
    ~BTree();
};


#endif //HARFS_CLIENT_BTREE_H
