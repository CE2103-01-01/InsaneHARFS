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
    std::fstream inputFile(path.c_str());
    if (!inputFile.is_open()) {
        printf((COULD_NOT_CREATE_FILE+path).c_str());
        return -1;
    }
    inputFile.seekg(offset);
    inputFile << *data;
    inputFile.close();
    return 0;
}

char *FileHandler::read(const std::string &path, const int & offset, const int& size) {
    if (checkFileExistence(path)) {
        std::fstream outputFile(path.c_str());
        char* toRet = static_cast<char*>(malloc(size));
        outputFile.read(toRet, size);
        return toRet;
    }else{
        printf(FILE_DOES_NOT_EXIST);
        return NULL;
    }
}
