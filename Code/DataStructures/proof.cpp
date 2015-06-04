//
// Created by roberto on 04/06/15.
//

#include "proof.h"


template <typename AnyType> void printTree(DoubleLinkedNode<AnyType>* node){
    if(node->getPrevious()) printTree<AnyType>(node->getPrevious());
    std::cout << *node->getData() << std::endl;
    if(node->getNext()) printTree<AnyType>(node->getNext());
}

void proofDoubleLinkedListWithBinaryTree() {
    //Crea una lista
    DoubleLinkedList<BinaryTree<int>>* proof
            = static_cast<DoubleLinkedList<BinaryTree<int>>*>(malloc(sizeof(DoubleLinkedList<BinaryTree<int>>)));
    new(proof) DoubleLinkedList<BinaryTree<int>>();
    for(int i = 0; i<1000; i++){
        //Inserta un arbol a la cabeza
        proof->insertNewHead(BinaryTree<int>());
        BinaryTree<int>* tmp = proof->getHead()->getData();
        for(int j=0; j<1000; j++){
            //Si el numero es par lo inserta
            if(j%2==0)tmp->insertData(j);
                //Si el numero es impar le resta uno e inserta el negativo
            else tmp->insertData(-(j-1));
        }
        printTree<int>(tmp->getRoot());
    }
}