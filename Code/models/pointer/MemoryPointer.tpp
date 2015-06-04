//
// Created by pablo on 01/06/15.
//


#include "MemoryPointer.h"

/**
 * Sets data of a pointer
 */
template <class T>
void MemoryPointer<T>::set(T data) {
    *static_cast<T*>(pointer) = data;
}
/**
 * Returns pointer of c++
 */
template <class T>
T *MemoryPointer<T>::get() {
    return static_cast<T*>(pointer);
}

/**
 * Free pointer of Memory
 */
template <class T>
void MemoryPointer<T>::free() {
    //free(pointer);
}
template <class T>
size_t MemoryPointer<T>::getSize() {
    return 0;
}
/**
 * Constructor with void*
 */
template <class T>
MemoryPointer<T>::MemoryPointer(void *pVoid) {
    pointer = pVoid;
}

/**
 * Assigment of a pointer
 */
template <class T>
MemoryPointer<T>& MemoryPointer<T>::operator=(void* purePointer)  {
    pointer = purePointer;
    return *this;
}
/**
 * Copy Constructor
 */
template <class T>
MemoryPointer<T>::MemoryPointer(const MemoryPointer &memoryPointer) {
    pointer = memoryPointer.pointer;
}

