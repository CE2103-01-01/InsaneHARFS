//
// Created by roberto on 05/06/15.
//

#ifndef HARFS_DISK_REGISTERMANAGER_H
#define HARFS_DISK_REGISTERMANAGER_H

#include <string>

// |     Siguiente  8 Bytes    |    Siguiente Vacio 8 Bytes    |       Dato  512 Bytes      |
#define NEXT 0
#define NEXT_LENGHT 8
#define NEXT_EMPTY 1
#define NEXT_EMPTY_LENGHT 8
#define DATA 2
#define DATA_LENGHT 128

class RegisterManager {
    std::string registerPath;
    long firstEmptyRegister;
    long usedRegisters;
    long numberOfRegisters;
    public:
        RegisterManager(std::string, long);
        long addRegister(char*, long);
        void* searchRegister(long);
        void deleteRegister(long);
};

#endif //HARFS_DISK_REGISTERMANAGER_H
