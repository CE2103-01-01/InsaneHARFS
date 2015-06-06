//
// Created by roberto on 25/05/15.
//

#include "FileManager.h"

/** Escritor de archivos
 * @brief guarda un archivo formato EXTENSION
 * @param: void* data: dato a guardar
 * @param: int id: numero de archivo
 * @param: int dSize: tamaño del dato
 */
void FileManager::writeFile(const char* data, std::string path, int offset, int dataSize) {
    std::fstream outFile(PathConstants::PROJECT_PATH+path+PathConstants::EXT, std::ios::out | std::ios::in | std::ios::ate);
    for(int i = 0; i < dataSize; i++) {
           outFile.seekp(offset + i);
           outFile << *(data + i);
    }
    outFile.close();
}

/** Lector de archivos
 * @brief lee un archivo formato EXTENSION
 * @param: void* ret: dato a cargar
 * @param: int id: numero de archivo
 * @param: int retSize: tamaño del dato
 */
void FileManager::readFile(char* ret, std::string path, int offset, int dataSize) {//T(11+6i)
    std::ifstream inFile(PathConstants::PROJECT_PATH+path+PathConstants::EXT, std::ios::binary);
    inFile.read(ret,dataSize);
    inFile.close();
}

/** Borra archivo
 * @brief borra un archivo formato EXTENSION
 * @param: int id: numero de archivo
 */
void FileManager::deleteFile(std::string path){
    remove((PathConstants::PROJECT_PATH+path+PathConstants::EXT).c_str());
}
