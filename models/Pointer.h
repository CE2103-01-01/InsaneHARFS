//
// Created by pablo on 01/06/15.
//

#ifndef INSANEHARFS_POINTER_H
#define INSANEHARFS_POINTER_H

#include <glob.h>
#include <stdlib.h>
/**
 * Class that abstracts a pointer
 */

template < typename T > class Pointer
{
private:
    T*    pData;  //pointer

public:
    Pointer() : pData(0)
    {
    }
    Pointer(T* pValue) : pData(pValue)
    {
    }
    Pointer(void* pValue) : pData( static_cast<T*>(pValue) )
    {

    }

    Pointer(const Pointer<T>& sp) : pData(sp.pData)
    {
    }

    ~Pointer()
    {
    }

    T& operator* ()
    {
        return *pData;
    }

    T* operator-> ()
    {
        return pData;
    }

    Pointer<T>& operator = (const Pointer<T>& sp)
    {
        // Assignment operator
        if (this != &sp) // Avoid self assignment
        {
            pData = sp.pData;
        }
        return *this;
    }
    void Free() {
        free(pData);
    }
    size_t getSize();
};
#endif //INSANEHARFS_POINTER_H
