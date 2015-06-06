//
// Created by pablo on 03/06/15.
//

#ifndef HARFS_DISK_FILEMANAGER_H
#define HARFS_DISK_FILEMANAGER_H

#include <fstream>

#define FILE_DOES_NOT_EXIST "File does not exists."
#define COULD_NOT_CREATE_FILE "Could not create file."

class FileHandler {
    static bool checkFileExistence(const std::string&);
    static int write(const std::string&, const int&, char*);
    static char* read(const std::string&, const int &, const int&);
};


#endif //HARFS_DISK_FILEMANAGER_H
