//
// Created by roberto on 25/05/15.
//

#ifndef PROJECTMIDGARDLOGIC_BIRTHWRITER_H
#define PROJECTMIDGARDLOGIC_BIRTHWRITER_H

#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include "../pathConstants.h"
#include "../Exceptions.h"
#include "../dataStructuresOnHD/Buffer.h"

#define NULL_CHR " "
#define NULL_CHR_SIZE 1

class FileManager{
public:
    static void createFile(std::string path, int);
    static void writeFile(void*, std::string, int, int);
    static void readFile(void*, std::string, int, int);
    static Buffer* readFile(std::string, int, int);
    static void deleteFile(std::string);
};


#endif //PROJECTMIDGARDLOGIC_BIRTHWRITER_H
