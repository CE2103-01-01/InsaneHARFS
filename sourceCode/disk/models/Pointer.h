//
// Created by pablo on 01/06/15.
//

#ifndef INSANEHARFS_POINTER_H
#define INSANEHARFS_POINTER_H

class Pointer{
    unsigned int id = 0;
    void* data = 0;
    public:
        Pointer(int);
        ~Pointer();
        Pointer operator =(int);
        Pointer operator =(const Pointer&);
        bool operator ==(int);
        bool operator !=(int);
        bool operator <=(int);
        bool operator >=(int);
        bool operator <(int);
        bool operator >(int);
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
        Pointer operator -(int);
        Pointer operator +(int);
        Pointer operator *(int);
        Pointer operator /(int);
        Pointer operator -=(int);
        Pointer operator +=(int);
        Pointer operator /=(int);
        Pointer operator *=(int);
        void* operator *();
};

#endif //INSANEHARFS_POINTER_H
