//
// Created by pablo on 01/06/15.
//

#ifndef INSANEHARFS_POINTER_H
#define INSANEHARFS_POINTER_H

class Pointer{
    unsigned long id;
    void* data;
    public:
        Pointer();
        Pointer(long);
        void operator =(long);
        bool operator ==(long);
        bool operator !=(long);
        bool operator <=(long);
        bool operator >=(long);
        bool operator <(long);
        bool operator >(long);
        void operator =(Pointer);
        bool operator ==(Pointer);
        bool operator !=(Pointer);
        bool operator <=(Pointer);
        bool operator >=(Pointer);
        bool operator <(Pointer);
        bool operator >(Pointer);
        Pointer operator ++(Pointer);
        Pointer operator ++();
        Pointer operator --(Pointer);
        Pointer operator --();
        void* operator *();
};

#endif //INSANEHARFS_POINTER_H
