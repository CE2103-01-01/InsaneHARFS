//
// Created by pablo on 01/06/15.
//

#ifndef INSANEHARFS_POINTER_H
#define INSANEHARFS_POINTER_H

class Pointer{
    unsigned long id = 0;
    void* data = 0;
    public:
        Pointer(long);
        ~Pointer();
        Pointer operator =(long);
        Pointer operator =(const Pointer&);
        bool operator ==(long);
        bool operator !=(long);
        bool operator <=(long);
        bool operator >=(long);
        bool operator <(long);
        bool operator >(long);
        bool operator ==(Pointer);
        bool operator !=(Pointer);
        bool operator <=(Pointer);
        bool operator >=(Pointer);
        bool operator <(Pointer);
        bool operator >(Pointer);
        Pointer operator -(Pointer);
        Pointer operator +(Pointer);
        Pointer operator *(Pointer);
        Pointer operator /(Pointer);
        Pointer operator -=(Pointer);
        Pointer operator +=(Pointer);
        Pointer operator /=(Pointer);
        Pointer operator *=(Pointer);
        Pointer operator -(long);
        Pointer operator +(long);
        Pointer operator *(long);
        Pointer operator /(long);
        Pointer operator -=(long);
        Pointer operator +=(long);
        Pointer operator /=(long);
        Pointer operator *=(long);
        void* operator *();
};

#endif //INSANEHARFS_POINTER_H
