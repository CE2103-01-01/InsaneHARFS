//
// Created by roberto on 03/06/15.
//

#ifndef HARFS_DISK_BINARYTREE_H
#define HARFS_DISK_BINARYTREE_H

#include "DoubleLinkedNode.h"

#define NOT_FOUND_ERROR "ERROR, ELEMENTO NO ENCONTRADO"

template <typename AnyType> class BinaryTree {
    long nodeCounter;
    DoubleLinkedNode<AnyType>* root = 0;
    void copyPreOrden(DoubleLinkedNode<AnyType>*, DoubleLinkedNode<AnyType>*);
    public:
        BinaryTree();
        BinaryTree(const BinaryTree&);
        ~BinaryTree();
        void operator =(const BinaryTree&);
        void insertData(AnyType*);
        void insertData(AnyType);
        void deleteData(AnyType);
        AnyType* getData(AnyType);
        DoubleLinkedNode<AnyType>* getRoot();
        void postOrden(DoubleLinkedNode<AnyType>*, void(*)(void*));
        void preOrden(DoubleLinkedNode<AnyType>*, void(*)(void*));
        void inOrden(DoubleLinkedNode<AnyType>*, void(*)(void*));
};

/**@brief Constructor
 */
template <typename AnyType> BinaryTree<AnyType>::BinaryTree(){
    nodeCounter = 0;
    root = NULL;
}

/**@brief Constructor copia
 */
template <typename AnyType> BinaryTree<AnyType>::BinaryTree(const BinaryTree& toCopy){
    if(nodeCounter) postOrden(root,free);
    nodeCounter = toCopy.nodeCounter;
    if(nodeCounter) copyPreOrden(root,toCopy.root);
}

/**@brief Operador de igualdad
 */
template <typename AnyType> void BinaryTree<AnyType>::operator =(const BinaryTree& toCopy){
    if(nodeCounter) postOrden(root,free);
    nodeCounter = toCopy.nodeCounter;
    if(nodeCounter) copyPreOrden(root,toCopy.root);
}

/**@brief Destructor
 */
template <typename AnyType> BinaryTree<AnyType>::~BinaryTree(){
    postOrden(root,free);
}

/**@brief copia en inorden
 * @param DoubleLinkedNode<AnyType>* subTree: subarbol a recorrer
 * @param DoubleLinkedNode<AnyType>* subTree: subarbol a recorrer
 */
template <typename AnyType> void BinaryTree<AnyType>::copyPreOrden(DoubleLinkedNode<AnyType>* toSave, DoubleLinkedNode<AnyType>* toCopy) {
    if(toCopy){
        toSave = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
        new(toSave) DoubleLinkedNode<AnyType>();
        toSave->setData(toCopy->getData());
        if(toCopy->getNext()) copyPreOrden(toSave->getNext(), toCopy->getNext());
        if(toCopy->getNext()) copyPreOrden(toSave->getPrevious(), toCopy->getPrevious());
    }
}


/**@brief recorre en preorden
 * @param DoubleLinkedNode<AnyType>* subTree: subarbol a recorrer
 * @param void* method(void*): metodo a ejecutar
 */
template <typename AnyType> void BinaryTree<AnyType>::preOrden(DoubleLinkedNode<AnyType>* subTree, void(method)(void*)) {
    method(subTree);
    if(subTree->getPrevious()) preOrden(subTree->getPrevious(), method);
    if(subTree->getPrevious()) preOrden(subTree->getPrevious(), method);
}

/**@brief recorre en inorden
 * @param DoubleLinkedNode<AnyType>* subTree: subarbol a recorrer
 * @param void* method(void*): metodo a ejecutar
 */
template <typename AnyType> void BinaryTree<AnyType>::inOrden(DoubleLinkedNode<AnyType>* subTree, void(method)(void*)) {
    if(subTree->getPrevious()) inOrden(subTree->getPrevious(), method);
    method(subTree);
    if(subTree->getPrevious()) inOrden(subTree->getPrevious(), method);
}

/**@brief recorre en postorden
 * @param DoubleLinkedNode<AnyType>* subTree: subarbol a recorrer
 * @param void* method(void*): metodo a ejecutar
 */
template <typename AnyType> void BinaryTree<AnyType>::postOrden(DoubleLinkedNode<AnyType>* subTree, void(method)(void*)) {
    if(subTree){
        if(subTree->getPrevious()) postOrden(subTree->getPrevious(), method);
        if(subTree->getPrevious()) postOrden(subTree->getPrevious(), method);
        method(subTree);
    }
}

/**@brief inserta un dato
 * @param AnyType dato a insertar
 */
template <typename AnyType> void BinaryTree<AnyType>::insertData(AnyType* toInsert){
    insertData(*toInsert);
}

/**@brief inserta un dato
 * @param AnyType dato a insertar
 */
template <typename AnyType> void BinaryTree<AnyType>::insertData(AnyType toInsert){
    //Si existe la raiz analiza el arbol
    if(root){
        //Toma la raiz e inicia un ciclo
        DoubleLinkedNode<AnyType>* tmp = root;
        //En algun momento encontrara un espacio y ejecutara el break, por lo cual es innecesaria una bandera
        while(true){
            //Si el dato es mayor lo inserta a la derecha
            if(*tmp->getData() < toInsert){
                //Si ya el hijo existe, avanza
                if(tmp->getNext()) tmp = tmp->getNext();
                //Si no existe lo inserta ahi
                else{
                    tmp->setNext(static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>))));
                    new(tmp->getNext()) DoubleLinkedNode<AnyType>*();
                    tmp->getNext()->setData(toInsert);
                    nodeCounter++;
                    break;
                }
            }//Si el dato es menor lo inserta a la izquierda
            else{
                //Si ya el hijo existe, avanza
                if(tmp->getPrevious()) tmp = tmp->getPrevious();
                    //Si no existe lo inserta ahi
                else{
                    tmp->setPrevious(static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>))));
                    new(tmp->getPrevious()) DoubleLinkedNode<AnyType>*();
                    tmp->getPrevious()->setData(toInsert);
                    nodeCounter++;
                    break;
                }

            }
        }
    }//Si no existe la raiz la crea
    else{
        root = static_cast<DoubleLinkedNode<AnyType>*>(malloc(sizeof(DoubleLinkedNode<AnyType>)));
        new(root) DoubleLinkedNode<AnyType>();
        root->setData(toInsert);
    }
}

/**@brief borra un dato
 * @param AnyType dato a borrar
 */
template <typename AnyType> void BinaryTree<AnyType>::deleteData(AnyType toDelete){
    //Toma la raiz e inicia un ciclo
    DoubleLinkedNode<AnyType>* father = root;
    DoubleLinkedNode<AnyType>* found;
    DoubleLinkedNode<AnyType>* selected;
    //El ciclo termina si no se encuentra el dato
    while(father){
        //Si el dato es mayor lo avanza por la derecha
        if(*father->getData() < toDelete) {
            //Si el dato no es el buscado, se continua con el subarbol correspondiente
            if(father->getNext()!=toDelete) father = father->getNext();
            //Si es el buscado, se asigna al encontrado    
            else found = father->getNext();
        }//Si el dato es menor lo avanza por la izquierda
        else{
            //Si el dato no es el buscado, se continua con el subarbol correspondiente
            if(father->getPrevious()!=toDelete) father = father->getPrevious();
            //Si es el buscado, se asigna al encontrado
            else found = father->getPrevious();
        }
        if(found){
            //Si existen nodos a la derecha, los selecciona
            if(found->getNext()){
                //Los de la derecha son los mayores
                selected = found->getNext();
                //Itera hasta encontrar al menor de los mayores y lo selecciona
                while(selected->getPrevious()) selected=selected->getPrevious();
                //coloca ahi al subarbol de menor valor
                selected->setPrevious(found->getPrevious());
            }else if(found->getPrevious()){
                //Los de la izquierda son los menores
                selected = found->getPrevious();
                //Itera hasta encontrar al mayor de los menores y lo selecciona
                while(selected->getNext()) selected=selected->getNext();
                //coloca ahi al subarbol de mayor valor
                selected->setNext(found->getNext());
            }
            //Inserta al seleccionado en el lugar correspondiente
            if(found==father->getNext())father->setNext(selected);
            else father->setPrevious(selected);
            //borra lo que se pidio y corta el ciclo,
            free(found);
            nodeCounter--;
            break;
        }
    }
}

/**@brief devuelve un dato
 * @return AnyType*
 */
template <typename AnyType> AnyType* BinaryTree<AnyType>::getData(AnyType toGet){
    DoubleLinkedNode<AnyType>* found;
    while(found->getData()!=toGet){
        //Si el dato no es nulo sigue la busqueda
        if(found) {
            //Si el dato es mayor, avanza por la derecha
            if (toGet > found->getData()) found = found->getNext();
                //Si el dato es menor, avanza por la izquierda
            else found = found->getPrevious();
        }//Si el dato es nulo es porque no esta, por lo que retorna nulo
        else{ 
            printf(NOT_FOUND_ERROR);
            return NULL;
        }
    }
    return found->getData();
}

/**@brief accede a la raiz
 * @return DoubleLinkedNode<AnyType*>
 */
template <typename AnyType> DoubleLinkedNode<AnyType>* BinaryTree<AnyType>::getRoot(){
    return root;
}

#endif //HARFS_DISK_BINARYTREE_H
