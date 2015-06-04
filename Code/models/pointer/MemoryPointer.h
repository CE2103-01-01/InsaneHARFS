//
// Created by pablo on 01/06/15.
//

#ifndef INSANEHARFS_MEMORYPOINTER_H
#define INSANEHARFS_MEMORYPOINTER_H


#include "Pointer.h"
/**
 * Abstract memory pointer.
 * Usage:
 */
template <class T>
class MemoryPointer : public Pointer<T> {
private:
    void* pointer;
public:
    virtual void set(T) override;

    virtual void free() override;

    virtual size_t getSize() override;

    virtual  T *get() override;
    MemoryPointer(void *pVoid);
    MemoryPointer<T>& operator=(void* );
    MemoryPointer(const MemoryPointer&);


};
#include "MemoryPointer.tpp"

#endif //INSANEHARFS_MEMORYPOINTER_H
