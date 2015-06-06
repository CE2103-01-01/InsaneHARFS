#include "sourceCode/managers/FileManager.h"
/**
 * Usage: goto edit configurations and then program arguments:
 * insert this --config res/config.cfg
 */
int main(int argc, char* argv[]) {
    std::string path = "proof";
    char* text = "aaaaaaaaaa";
    char* change = "bbbbb";
    int offset = 2;
    int sizeOfText = 10;
    int sizeOfChange = 5;
    void* completeTextReaded = malloc(sizeOfText);
    void* changeReaded = malloc(sizeOfChange);
    FileManager::createFile(text,path,sizeOfText);
    FileManager::writeFile(change,path,offset,sizeOfChange);
    FileManager::readFile(completeTextReaded, path, NULL, sizeOfText);
    FileManager::readFile(changeReaded, path, offset, sizeOfChange);
    for(int i = 0; i < sizeOfText; i++) std::cout << *static_cast<char*>(completeTextReaded+i);
    std::cout << std::endl;
    for(int i = 0; i < sizeOfChange; i++) std::cout << *static_cast<char*>(changeReaded+i);
    std::cout << std::endl;
    return 0;
}
