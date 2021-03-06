//
// Created by pablo on 07/06/15.
//

#ifndef HARFS_CLIENT_UI_H
#define HARFS_CLIENT_UI_H

#include "../network/JsonWriter.h"
#include <ostream>
#include <iostream>
#include "../network/TCPClient.h"
using namespace std;
#define SLEEP 100000
#define WELCOME "Welcome to the High Availability Register File System"
#define COLUMNS_INSTRUCTS "Define the columns and the size of data of each one:\nNumber of columns:"
#define COLUMN "Size in bytes of column:"
#define OPTIONS  "Options:1-Create Storage Block \n2-List Storage Block\n3-Delete a Storage Bloc\n4-Define a Schema\n5-Save Register\n6-Delete Register\n7-Search Register\n8-Get Register\n9-Create User\n10-Permission to Storage Block\n11-Test permission\n12-Exit"
class CLI {
private:
    CLI();
    static CLI* singleton;
    string userName;
    void* table;
    bool signIn;
    bool defineRegister;
    bool existeStorage;
    int *columns;

    void defineSchema();
    void cycleOptions();
    void createStorageBlock();
    void listStorageBlock();
    void deleteStorageBlock();
    void saveRegister();
    void deleteRegister();
    void getRegister();
    void createUser();
    void setPermission();
    void testPermission();
    void insertDataAux(string);
    void saveFile(string,string);
    string getFile(string);
    void insertData();
    bool existFile(string);

public:
    void logIn();
    static CLI *getInstance();
    void messageHandler(string);
    ~CLI();
};


#endif //HARFS_CLIENT_UI_H
