#include "sourceCode/managers/FileManager.h"
/**
 * Usage: goto edit configurations and then program arguments:
 * insert this --config res/config.cfg
 */
int main(int argc, char* argv[]) {
    std::string path = "proof.bin";
    char* text = "proof";
    FileManager::writeFile(text,path,0,5);
    FileManager::writeFile("ab",path,0,2);


    return 0;
}
