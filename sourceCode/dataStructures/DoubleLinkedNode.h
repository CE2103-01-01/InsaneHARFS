//
// Created by roberto on 03/06/15.
//

#ifndef INSANEHARFS__DOUBLELINKEDNODE_H
#define INSANEHARFS__DOUBLELINKEDNODE_H

#include <malloc.h>

template <typename AnyType> class DoubleLinkedNode{
    AnyType* data;
    DoubleLinkedNode<AnyType>* next;
    DoubleLinkedNode<AnyType>* previous;
    public:
        DoubleLinkedNode();
        DoubleLinkedNode(const DoubleLinkedNode<AnyType>&);
        ~DoubleLinkedNode();
        void operator =(const DoubleLinkedNode<AnyType>&);
        void setData(AnyType);
        void setData(AnyType*);
        void setNext(DoubleLinkedNode<AnyType>*);
        void setPrevious(DoubleLinkedNode<AnyType>*);
        AnyType* getData();
        DoubleLinkedNode<AnyType>* getNext();
        DoubleLinkedNode<AnyType>* getPrevious();
};



/**@brief constructor por defecto
 */
template <typename AnyType> DoubleLinkedNode<AnyType>::DoubleLinkedNode(){
    data = NULL;
    previous = NULL;
    next = NULL;
}

/**@brief constructor de copia
 * @param const DoubleLinkedNode& toCopy: variable a copiar
 */
template <typename AnyType> DoubleLinkedNode<AnyType>::DoubleLinkedNode(const DoubleLinkedNode<AnyType>& toCopy){
    if(data && toCopy.data) {
        *data = *toCopy.data;
    }else if(toCopy.data){
        data = static_cast<AnyType*>(malloc(sizeof(AnyType)));
        *data = *toCopy.data;
    }
    previous = toCopy.previous;
    next = toCopy.next;
}

/**@brief operador de igualdad
 * @param const DoubleLinkedNode& toCopy: variable a copiar
 */
template <typename AnyType> void DoubleLinkedNode<AnyType>::operator =(const DoubleLinkedNode<AnyType>& toCopy){
    if(data && toCopy.data) {
        *data = *toCopy.data;
    }else if(toCopy.data){
        data = static_cast<AnyType*>(malloc(sizeof(AnyType)));
        *data = *toCopy.data;
    }
    previous = toCopy.previous;
    next = toCopy.next;
}

/**@brief destructor
 */
template <typename AnyType> DoubleLinkedNode<AnyType>::~DoubleLinkedNode(){
    free(data);
    previous = 0;
    next = 0;
}

/**@brief metodo que inserta un dato
 * @param AnyType toInsert: dato a insertar
 */
template <typename AnyType> void DoubleLinkedNode<AnyType>::setData(AnyType toInsert){
    if(data) *data = toInsert;
    else{
        data = static_cast<AnyType*>(malloc(sizeof(AnyType)));
        *data = toInsert;
    }
}


/**@brief metodo que inserta un dato
 * @param AnyType toInsert: dato a insertar
 */
template <typename AnyType> void DoubleLinkedNode<AnyType>::setData(AnyType* toInsert){
    if(data) free(data);
    data = toInsert;
}

/**@brief metodo que coloca a un nodo como siguiente
 * @param DoubleLinkedNode<AnyType>* newNext: nodo a colocar
 */
template <typename AnyType> void DoubleLinkedNode<AnyType>::setNext(DoubleLinkedNode<AnyType>* newNext){
    next=newNext;
}

/**@brief metodo que coloca a un nodo como anterior
 * @param DoubleLinkedNode<AnyType>* newPrevious: nodo a colocar
 */
template <typename AnyType> void DoubleLinkedNode<AnyType>::setPrevious(DoubleLinkedNode<AnyType>* newPrevious){
    previous=newPrevious;
}

/**@brief accede al dato
 * @return AnyType*
 */
template <typename AnyType> AnyType* DoubleLinkedNode<AnyType>::getData(){
    return data;
}

/**@brief accede al siguiente
 * @return DoubleLinkedNode<AnyType>*
 */
template <typename AnyType> DoubleLinkedNode<AnyType>* DoubleLinkedNode<AnyType>::getNext(){
    return next;
}

/**@brief accede al anterior
 * @return DoubleLinkedNode<AnyType>*
 */
template <typename AnyType> DoubleLinkedNode<AnyType>* DoubleLinkedNode<AnyType>::getPrevious(){
    return previous;
}

#endif //INSANEHARFS__DOUBLELINKEDNODE_H
