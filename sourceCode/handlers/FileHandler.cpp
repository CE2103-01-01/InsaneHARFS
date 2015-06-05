//
// Created by pablo on 03/06/15.
//

#include "FileHandler.h"

/**
 * Search if a file exists
 */
bool FileHandler::checkFileExistence(const std::string& path) {
    std::ifstream f(path.c_str());
    bool open = f.is_open();
    f.close();
    return open;
}

/**
 * writes char* on a file
 * Exit codes:
 * 0: write successful
 * 1: file created
 * -1: file couldnt create
 */
int FileHandler::write(const std::string &path, const int & offset, char *data) {
    std::fstream inputFile;
    const bool exists = checkFileExistence(path);
    if (!exists) {
        printf((FILE+path+NOT_FOUND).c_str());
        inputFile.open(path.c_str());
        if (!inputFile.is_open()) {
            printf(COULD_NOT_CREATE_FILE);
            return -1;
        }
        printf(FILE_CREATED);
    }
    else inputFile.open(path.c_str());

    inputFile.seekg(offset);
    inputFile << *data;
    inputFile.close();
    if (exists) return 0;
    else return 1;
}

char *FileHandler::read(const std::string &path, const int & offset, const int& size) {
    const bool exists = checkFileExistence(path);
    if (!exists) {
        printf(FILE_DOES_NOT_EXIST);
        return NULL;
    }
    std::fstream outputFile(path.c_str());
}
