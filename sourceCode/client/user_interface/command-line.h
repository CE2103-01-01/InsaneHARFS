//
// Created by pablo on 07/06/15.
//

#ifndef HARFS_CLIENT_UI_H
#define HARFS_CLIENT_UI_H

#include <ostream>
#include <iostream>
using namespace std;

#define WELCOME "Welcome to the High Availability Register File System"
#define COLUMNS_INSTRUCTS "Define the columns and the size of data of each one:\nNumber of columns:"
#define COLUMN "Size in bytes of column:"
#define OPTIONS "Select: 1:"
class CLI {
private:
    bool existeRegister;
    bool existeStorage;
    int *columns;
    void defineSchema();
    void cycleOptions();
    void createStorageBlock();
    void listStorageBlock();
    void deleteStorageBlock();
    void saveRegister();
    void deleteRegister();
    void search();
    void getRegister();
    void createUser();
    void setPermission();
    void testPermission();
public:
    CLI();
    ~CLI();
};


#endif //HARFS_CLIENT_UI_H
