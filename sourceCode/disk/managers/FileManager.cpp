//
// Created by roberto on 25/05/15.
//

#include "FileManager.h"

/** Crear de archivos
 * @brief guarda un archivo formato EXTENSION
 * @param: void* data: dato a guardar
 * @param: int dSize: tamaño del dato
 */
void FileManager::createFile(std::string name, int dataSize) {
    std::fstream outFile(PathConstants::PROJECT_PATH+name+PathConstants::EXT, std::ios::out);
    for(int i = 0; i < dataSize; i++) outFile.write(NULL_CHR,NULL_CHR_SIZE);
    outFile.close();
}

/** Escritor de archivos
 * @brief guarda un archivo formato EXTENSION
 * @param: void* data: dato a guardar
 * @param: int id: numero de archivo
 * @param: int dSize: tamaño del dato
 */
void FileManager::writeFile(void* data, std::string name, int offset, int dataSize) {
    std::fstream outFile(PathConstants::PROJECT_PATH+name+PathConstants::EXT, std::ios::out | std::ios::in | std::ios::ate);
    outFile.seekp(offset);
    for(int i = 0; i < dataSize; i++) outFile.write(static_cast<char*>(data+i),1);
    outFile.close();
}

/** Lector de archivos
 * @brief lee un archivo formato EXTENSION
 * @param: void* ret: dato a cargar
 * @param: int id: numero de archivo
 * @param: int retSize: tamaño del dato
 */
void FileManager::readFile(void* ret, std::string path, int offset, int dataSize) {//T(11+6i)
    std::ifstream inFile(PathConstants::PROJECT_PATH+path+PathConstants::EXT, std::ios::binary);
    inFile.seekg(offset);
    inFile.read(static_cast<char*>(ret),dataSize);
    inFile.close();
}

/** Borra archivo
 * @brief borra un archivo formato EXTENSION
 * @param: int id: numero de archivo
 */
void FileManager::deleteFile(std::string path){
    remove((PathConstants::PROJECT_PATH+path+PathConstants::EXT).c_str());
}
