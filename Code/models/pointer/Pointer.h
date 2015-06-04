//
// Created by pablo on 01/06/15.
//

#ifndef INSANEHARFS_POINTER_H
#define INSANEHARFS_POINTER_H

#include <glob.h>

/**
 * Class that abstracts a pointer
 */
template <class T>
class Pointer {
public:
    virtual void set(T) = 0;
    virtual T *get() = 0;
    virtual void free() = 0;
    virtual size_t getSize() = 0;
};


#endif //INSANEHARFS_POINTER_H
