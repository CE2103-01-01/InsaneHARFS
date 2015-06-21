//
// Created by roberto on 03/06/15.
//

#ifndef INSANEHARFS_DOUBLELINKEDLIST_H
#define INSANEHARFS_DOUBLELINKEDLIST_H


#include "DoubleLinkedNode.h"

#define POSITION_ERROR "ERROR EN DoubleLinkedList, LA POSICION SUMINISTRADA ESTA FUERA DE RANGO"

template <typename AnyType> class DoubleLinkedList {
    long nodeCounter;
    DoubleLinkedNode<AnyType>* head;
    DoubleLinkedNode<AnyType>* tail;
    public:
        DoubleLinkedList();
        DoubleLinkedList(const DoubleLinkedList<AnyType>&);
        ~DoubleLinkedList();
        void operator=(const DoubleLinkedList<AnyType>&);
        void insertNewHead(AnyType);
        void insertNewHead(AnyType*);
        void insertNewTail(AnyType);
        void insertNewTail(AnyType*);
        void deleteData(AnyType);
        void deleteLink(AnyType *);
        void deleteData(long);
        void deleteLink(long);
        DoubleLinkedNode<AnyType>* getNode(long);
        AnyType* getData(long);
        DoubleLinkedNode<AnyType>* getHead();
        DoubleLinkedNode<AnyType>* getTail();
        long lenght();
};


/**@brief constructor por defecto
 */
template <typename AnyType> DoubleLinkedList<AnyType>::DoubleLinkedList(){
    nodeCounter = 0;
    head = 0;
    tail = 0;
}

/**@brief constructor de copia
 */
template <typename AnyType> DoubleLinkedList<AnyType>::DoubleLinkedList(const DoubleLinkedList<AnyType>& toCopy){
    //Si existen nodos los borra
    if(nodeCounter){
        DoubleLinkedNode<AnyType>* tmpNode = head;
        for(int i=0; i<nodeCounter; i++){
            DoubleLinkedNode<AnyType>* toDelete = tmpNode;
            tmpNode = tmpNode->getNext();
            free(toDelete);
        }
    }
    //Copia los nodos
    if(toCopy.nodeCounter){
        nodeCounter = toCopy.nodeCounter;
        head = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
        DoubleLinkedNode<AnyType>* copy = head;
        DoubleLinkedNode<AnyType>* readed = toCopy.head;
        //Itera sobre ambas listas copiando los datos
        for(int i = 0; i < nodeCounter; i++){
            new(copy) DoubleLinkedNode<AnyType>(*readed->getData());
            copy->setNext(static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>))));
            copy = copy->getNext();
            readed = readed->getNext();
        }
        tail = copy;
    }else{
        head = 0;
        tail = 0;
        nodeCounter = 0;
    }
}

/**@brief destructor
 */
template <typename AnyType> DoubleLinkedList<AnyType>::~DoubleLinkedList(){
    DoubleLinkedNode<AnyType>* tmpNodeOne = head;
    for(int i=0; i<nodeCounter; i++){
        DoubleLinkedNode<AnyType>* tmpNodeTwo = tmpNodeOne->getNext();
        free(tmpNodeOne);
        tmpNodeOne = tmpNodeTwo;
    }
    head = 0;
    tail = 0;
    nodeCounter = 0;
}

/**@brief operador de igualdad
 */
template <typename AnyType> void DoubleLinkedList<AnyType>::operator=(const DoubleLinkedList<AnyType>& toCopy){
    //Si existen nodos los borra
    if(nodeCounter){
        DoubleLinkedNode<AnyType>* tmpNode = head;
        for(int i=0; i<nodeCounter; i++){
            DoubleLinkedNode<AnyType>* toDelete = tmpNode;
            tmpNode = tmpNode->getNext();
            free(toDelete);
        }
    }
    //copia los nodos
    if(toCopy.nodeCounter){
        nodeCounter = toCopy.nodeCounter;
        head = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
        DoubleLinkedNode<AnyType>* copy = head;
        DoubleLinkedNode<AnyType>* readed = toCopy.head;
        //Itera sobre ambas listas copiando los datos
        for(int i = 0; i < nodeCounter; i++){
            new(copy) DoubleLinkedNode<AnyType>(*readed->getData());
            copy->setNext(static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>))));
            copy = copy->getNext();
            readed = readed->getNext();
        }
        tail = copy;
    }else{
        head = 0;
        tail = 0;
        nodeCounter = 0;
    }
}

/**@brief inserta una nueva cabeza
 * @param AnyType* dataToInsert
 */
template <typename AnyType> void DoubleLinkedList<AnyType>::insertNewHead(AnyType dataToInsert){
    //Toma temporal y crea nuevo nodo
    DoubleLinkedNode<AnyType>* tmp = head;
    head = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
    new(head) DoubleLinkedNode<AnyType>();
    //Hace el reacomodo
    head->setData(dataToInsert);
    head->setNext(tmp);
    if(!tail) tail = tmp;
    nodeCounter++;
}

/**@brief inserta una nueva cabeza
 * @param AnyType* dataToInsert
 */
template <typename AnyType> void DoubleLinkedList<AnyType>::insertNewHead(AnyType* dataToInsert){
    //Toma temporal y crea nuevo nodo
    DoubleLinkedNode<AnyType>* tmp = head;
    head = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
    new(head) DoubleLinkedNode<AnyType>();
    //Hace el reacomodo
    head->setData(dataToInsert);
    head->setNext(tmp);
    if(!tail) tail = tmp;
    nodeCounter++;
}

/**@brief inserta una nueva cola
 * @param AnyType dataToInsert
 */
template <typename AnyType> void DoubleLinkedList<AnyType>::insertNewTail(AnyType dataToInsert){
    if(nodeCounter){
        DoubleLinkedNode<AnyType>* tmp;
        //Si ya hay nodos toma la cola, si no toma la cabeza
        if(tail) tmp = tail;
        else tmp = head;
        //Crea la nueva cola y hace el reacomodo
        tail = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
        new(tail) DoubleLinkedNode<AnyType>();
        tail->setData(dataToInsert);
        tail->setPrevious(tmp);
        tmp->setNext(tail);
    }else{
        //Si no hay nodos crea uno
        head = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
        new(head) DoubleLinkedNode<AnyType>();
        head->setData(dataToInsert);
    }
    nodeCounter++;
}

/**@brief inserta una nueva cola
 * @param AnyType* dataToInsert
 */
template <typename AnyType> void DoubleLinkedList<AnyType>::insertNewTail(AnyType* dataToInsert){
    if(nodeCounter){
        DoubleLinkedNode<AnyType>* tmp;
        //Si ya hay nodos toma la cola, si no toma la cabeza
        if(tail) tmp = tail;
        else tmp = head;
        //Crea la nueva cola y hace el reacomodo
        tail = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
        new(tail) DoubleLinkedNode<AnyType>();
        tail->setData(dataToInsert);
        tail->setPrevious(tmp);
        tmp->setNext(tail);
    }else{
        //Si no hay nodos crea uno
        head = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
        new(head) DoubleLinkedNode<AnyType>();
        head->setData(dataToInsert);
    }
    nodeCounter++;
}

/**@brief borra un dato
 * @brif long position
 */
template <typename AnyType> void DoubleLinkedList<AnyType>::deleteData(long position){
    //Verifica que el dato este en el rango y no sea la cabeza o la cola
    if(0<position && position<nodeCounter-1){
        //Bisca el nodo y realiza un reacomodo
        DoubleLinkedNode<AnyType>* toDelete = getNode(position);
        toDelete->getPrevious()->setNext(toDelete->getNext());
        toDelete->getNext()->setPrevious(toDelete->getPrevious());
        free(toDelete);
        nodeCounter--;
    }//Si el dato es la cabeza
    else if(position == 0){
        DoubleLinkedNode<AnyType>* toDelete = head;
        head = toDelete->getNext();
        free(toDelete);
        nodeCounter--;
    }//Si el dato es la cabeza
    else if(position == nodeCounter-1){
        DoubleLinkedNode<AnyType>* toDelete = tail;
        head = toDelete->getPrevious();
        free(toDelete);
        nodeCounter--;
    }//Si hay error
    else{
        printf(POSITION_ERROR);
    }
}

/**@brief busca un dato en la lista
 * @param long position
 * @return AnyType*
 */
template <typename AnyType> DoubleLinkedNode<AnyType>* DoubleLinkedList<AnyType>::getNode(long position){
    //Verifica que el dato este en el rango
    if(position<nodeCounter && position>=0){
        DoubleLinkedNode<AnyType>* toReturn;
        //Recorre la lista desde el inicio o final, segun sea mas conveniente
        if(position<(nodeCounter/2)){
            toReturn = head;
            //Inicia en 1 ya que la cabeza ha sido tomada
            for(int i=1; i<=position; i++) toReturn=toReturn->getNext();
        }else{
            toReturn = tail;
            //Inicia en nodeCounter-2 ya que la cola ha sido tomada
            for(int i=nodeCounter-2; i>=position; i--) toReturn=toReturn->getPrevious();
        }
        return toReturn;
    }else{
        printf(POSITION_ERROR);
        return 0;
    }
}

/**@brief busca un dato en la lista
 * @param long position
 * @return AnyType*
 */
template <typename AnyType> AnyType* DoubleLinkedList<AnyType>::getData(long position){
    //Verifica que el dato este en el rango
    if(position<nodeCounter && position>=0){
        return getNode(position)->getData();
    }else{
        printf(POSITION_ERROR);
        return 0;
    }
}

/**@brief accede a la cabeza
 */
template <typename AnyType> DoubleLinkedNode<AnyType>* DoubleLinkedList<AnyType>::getHead(){
    return head;
}

/**@brief accede al final
 * @return DoubleLinkedNode<AnyType>*
 */
template <typename AnyType> DoubleLinkedNode<AnyType>* DoubleLinkedList<AnyType>::getTail(){
    return tail;
}

/**@brief accede a la longitud
 * @return long
 */
template <typename AnyType> long DoubleLinkedList<AnyType>::lenght(){
    return nodeCounter;
}

template <typename AnyType> void DoubleLinkedList<AnyType>::deleteLink(AnyType *data) {
    DoubleLinkedNode<AnyType>* node = head;
    while(node!= nullptr && node->getData()!= data)
    {
        node = node->getNext();
    }
    if(!node) return;

    if(node->getPrevious()!= nullptr)node->getPrevious()->setNext(node->getNext());
    if(node->getNext()!= nullptr)node->getNext()->setPrevious(node->getPrevious());
}

#endif //INSANEHARFS__DOUBLELINKEDLIST_H


