//
// Created by pablo on 03/06/15.
//

#ifndef HARFS_DISK_FILEMANAGER_H
#define HARFS_DISK_FILEMANAGER_H

#include <string>
#include <fstream>

using namespace std;
class FileManager {
public:
    static bool checkFileExistence(const string&path);
    static int write(const string &path, const int &offset, char* data);
    static char* read(const string &path, const int & offset, const int& size);
};


#endif //HARFS_DISK_FILEMANAGER_H
