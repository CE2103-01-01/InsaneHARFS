#include "sourceCode/managers/FileManager.h"
/**
 * Usage: goto edit configurations and then program arguments:
 * insert this --config res/config.cfg
 */
int main(int argc, char* argv[]) {
    std::string path = "proof";
    char* text = "proof";
    FileManager::createFile(text,path,5);
    FileManager::writeFile("abb",path,2,3);
    return 0;
}
