//
// Created by pablo on 03/06/15.
//

#ifndef HARFS_DISK_FILEMANAGER_H
#define HARFS_DISK_FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class FileHandler {
private:
public:
    FileHandler();
    ~FileHandler();
    bool checkFileExistence(const string&path);
    int write(const string &path, const int &offset, char* data);
    char* read(const string &path, const int & offset, const int& size);
};


#endif //HARFS_DISK_FILEMANAGER_H
