//
// Created by roberto on 06/06/15.
//

#ifndef HARFS_CLIENT_REGISTERMANAGER_H
#define HARFS_CLIENT_REGISTERMANAGER_H



#include <fstream>
#include "../managers/FileManager.h"

// HEADER:      | PrimerVacio  4 Bytes | Usados 4 Bytes | Registros totales 4 Bytes | =  12 Bytes

#define REGISTER_MANAGER_HEADER_LENGHT 12
#define REGISTER_MANAGER_COMPONENT_LENGHT 4
#define FIRST_EMPTY_POSITION 0
#define USED_POSITION 1
#define MAX_REGISTERS_POSITION 2

// REGISTROS: | Siguiente Vacio 4 Bytes | Nombre  128 Bytes |
//            |Apellido 64 Bytes | Cedula 9 Bytes | Edad 1 Byte
//            | Profesion u oficio 50 Bytes |                      =  256 Bytes

#define REGISTER_LENGHT 256
#define NEXT_EMPTY_LENGHT 4
#define NAME_LENGHT 128
#define SURNAME_LENGHT 64
#define ID_LENGHT 9
#define AGE_LENGHT 1
#define OCCUPATION_LENGHT 50
#define NEXT_EMPTY_POSITION 0
#define NAME_POSITION 1
#define SURNAME_POSITION 2
#define ID_POSITION 3
#define AGE_POSITION 4
#define OCCUPATION_POSITION 5

class RegisterManager {
    std::string path;
    int firstEmptyRegister;
    int usedRegisters;
    int numberOfRegisters;
    void updateHeader();
public:
    RegisterManager(std::string, int);
    long addRegister(void*, long);
    void* searchRegister(void*, int, int);
    void deleteRegister(int);
    void print();
};

#endif //HARFS_CLIENT_REGISTERMANAGER_H
