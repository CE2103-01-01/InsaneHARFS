//
// Created by roberto on 25/05/15.
//

#ifndef PROJECTMIDGARDLOGIC_BIRTHWRITER_H
#define PROJECTMIDGARDLOGIC_BIRTHWRITER_H

#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include "../pathConstants.h"

class FileManager{
public:
    static void writeFile(const char*, std::string, int, int);
    static void readFile(char*, std::string, int, int);
    static void deleteFile(std::string);
};


#endif //PROJECTMIDGARDLOGIC_BIRTHWRITER_H
