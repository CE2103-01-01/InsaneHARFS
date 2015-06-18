//
// Created by roberto on 17/06/15.
//

#ifndef HARFS_CLIENT_BUFFER_H
#define HARFS_CLIENT_BUFFER_H


#include <malloc.h>
#include <string.h>
#include "../Exceptions.h"

class Buffer {
    int size;
    void* data;
    void copy(const Buffer&);
public:
    Buffer(int,void*);
    Buffer(const Buffer&);
    void operator =(const Buffer&);
    ~Buffer();
    void* get(int);
    void changeContent(int,void*);
};


#endif //HARFS_CLIENT_BUFFER_H
