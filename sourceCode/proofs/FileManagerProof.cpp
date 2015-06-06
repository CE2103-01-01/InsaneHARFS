//
// Created by roberto on 06/06/15.
//

#include "FileManagerProof.h"

/**@brief: la prueba consiste en la creacion de un archivo que se modifica en un offset, con el fin de verificar
 * el funcionamiento del metodo de creacion, lectura y escritura. El archivo modificado es cargado en una variable,
 * asi como su cambio, para imprimirlas en consola
 */
void fileManagerProofOne(){
    //Creacion
    std::string path = "proof";
    char* text = "aaaaaaaaaa";
    int sizeOfText = 10;
    FileManager::createFile(text,path,sizeOfText);
    //Modificacion
    char* change = "bbbbb";
    int sizeOfChange = 5;
    int offset = 2;
    FileManager::writeFile(change,path,offset,sizeOfChange);
    //Lectura
    void* completeTextReaded = malloc(sizeOfText);
    void* changeReaded = malloc(sizeOfChange);
    FileManager::readFile(completeTextReaded, path, NULL, sizeOfText);
    FileManager::readFile(changeReaded, path, offset, sizeOfChange);
    //Impresion
    std::cout<< "This is the first test"<<std::endl;
    for(int i = 0; i < sizeOfText; i++) std::cout << *static_cast<char*>(completeTextReaded+i);
    std::cout << std::endl;
    for(int i = 0; i < sizeOfChange; i++) std::cout << *static_cast<char*>(changeReaded+i);
    std::cout << std::endl;
}
void fileManagerProofTwo(){
    std::string path = "proof";
    char* text = "0000000000";
    char* change = "11111";
    int offset = 4;
    int sizeOfText = 10;
    int sizeOfChange = 5;
    void* completeTextReaded = malloc(sizeOfText);
    void* changeReaded = malloc(sizeOfChange);
    FileManager::createFile(text,path,sizeOfText);
    FileManager::writeFile(change,path,offset,sizeOfChange);
    FileManager::readFile(completeTextReaded, path, NULL, sizeOfText);
    FileManager::readFile(changeReaded, path, offset, sizeOfChange);
    std::cout<< "This is the second test"<<std::endl;
    for(int i = 0; i < sizeOfText; i++) std::cout << *static_cast<char*>(completeTextReaded+i);
    std::cout << std::endl;
    for(int i = 0; i < sizeOfChange; i++) std::cout << *static_cast<char*>(changeReaded+i);
    std::cout << std::endl;
}