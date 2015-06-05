//
// Created by pablo on 03/06/15.
//

#ifndef HARFS_DISK_FILEMANAGER_H
#define HARFS_DISK_FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>

#define FILE_DOES_NOT_EXIST "File does not exists."
#define FILE_CREATED "File created."
#define COULD_NOT_CREATE_FILE "Could not create file."
#define FILE "File "
#define NOT_FOUND " not found."

class FileHandler {
public:
    FileHandler();
    ~FileHandler();
    bool checkFileExistence(const std::string&path);
    int write(const std::string &path, const int &offset, char* data);
    char* read(const std::string &path, const int & offset, const int& size);
};


#endif //HARFS_DISK_FILEMANAGER_H
