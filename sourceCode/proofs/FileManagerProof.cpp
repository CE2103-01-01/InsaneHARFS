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
    std::string path = "FileManagerProofOne";
    char* text = "111111111";
    int sizeOfText = 9;
    FileManager::createFile(text,path,sizeOfText);
    //Modificacion
    char* change = "000";
    int sizeOfChange = 3;
    int offset = 0;
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
    free(completeTextReaded);
    free(changeReaded);
}

/**@brief: la prueba consiste en la creacion de un archivo que se modifica en un offset, con el fin de verificar
 * el funcionamiento del metodo de creacion, lectura y escritura. El archivo modificado es cargado en una variable,
 * asi como su cambio, para imprimirlas en consola
 */
void fileManagerProofTwo(){
    //Creacion
    std::string path = "FileManagerProofTwo";
    char* text = "111111111";
    int sizeOfText = 9;
    FileManager::createFile(text,path,sizeOfText);
    //Modificacion
    char* change = "000";
    int sizeOfChange = 3;
    int offset = 3;
    FileManager::writeFile(change,path,offset,sizeOfChange);
    //Lectura
    void* completeTextReaded = malloc(sizeOfText);
    void* changeReaded = malloc(sizeOfChange);
    FileManager::readFile(completeTextReaded, path, NULL, sizeOfText);
    FileManager::readFile(changeReaded, path, offset, sizeOfChange);
    //Impresion
    std::cout<< "This is the second test"<<std::endl;
    for(int i = 0; i < sizeOfText; i++) std::cout << *static_cast<char*>(completeTextReaded+i);
    std::cout << std::endl;
    for(int i = 0; i <  sizeOfChange; i++) printf(static_cast<char*>(changeReaded+i));
    std::cout << std::endl;
    free(completeTextReaded);
    free(changeReaded);
}

/**@brief: la prueba consiste en la creacion de un archivo que se modifica en un offset, con el fin de verificar
 * el funcionamiento del metodo de creacion, lectura y escritura. El archivo modificado es cargado en una variable,
 * asi como su cambio, para imprimirlas en consola
 */
void fileManagerProofThree(){
    //Creacion
    std::string path = "FileManagerProofThree";
    char* text = "111111111";
    int sizeOfText = 9;
    FileManager::createFile(text,path,sizeOfText);
    //Modificacion
    char* change = "000";
    int sizeOfChange = 3;
    int offset = 6;
    FileManager::writeFile(change,path,offset,sizeOfChange);
    //Lectura
    void* completeTextReaded = malloc(sizeOfText);
    void* changeReaded = malloc(sizeOfChange);
    FileManager::readFile(completeTextReaded, path, NULL, sizeOfText);
    FileManager::readFile(changeReaded, path, offset, sizeOfChange);
    //Impresion
    std::cout<< "This is the third test"<<std::endl;
    for(int i = 0; i < sizeOfText; i++) std::cout << *static_cast<char*>(completeTextReaded+i);
    std::cout << std::endl;
    for(int i = 0; i <  sizeOfChange; i++) printf(static_cast<char*>(changeReaded+i));
    std::cout << std::endl;
    free(completeTextReaded);
    free(changeReaded);
}