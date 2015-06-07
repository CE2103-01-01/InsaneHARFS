//
// Created by roberto on 25/05/15.
//

#include "FileManager.h"

/** Crear de archivos
 * @brief guarda un archivo formato EXT
 * @param: void* data: dato a guardar
 * @param: int dSize: tamaño del dato
 */
void FileManager::createFile(std::string name, int dataSize) {
    if(name.length()) {
        std::fstream outFile(PathConstants::PROJECT_PATH + name + PathConstants::EXT, std::ios::out);
        for (int i = 0; i < dataSize; i++) outFile.write(NULL_CHR, NULL_CHR_SIZE);
        outFile.close();
    }else{
        printf(NULL_PARAMETER);
        throw NULL_PARAMETER_CODE;
    }
}

/** Escritor de archivos
 * @brief guarda un archivo formato EXT
 * @param: void* data: dato a guardar
 * @param: int id: numero de archivo
 * @param: int dSize: tamaño del dato
 */
void FileManager::writeFile(void* data, std::string name, int offset, int dataSize) {
    if(offset>-1){
        if(name.length()){
            std::fstream outFile(PathConstants::PROJECT_PATH+name+PathConstants::EXT, std::ios::out | std::ios::in | std::ios::ate);
            outFile.seekp(offset);
            for(int i = 0; i < dataSize; i++) outFile.write(static_cast<char*>(data+i),1);
            outFile.close();
        }else{
            printf(NULL_PARAMETER);
            throw NULL_PARAMETER_CODE;
        }
    }else{
        printf(OFFSET_OUT_OF_BOUND);
        throw OFFSET_OUT_OF_BOUND_CODE;
    }
}

/** Lector de archivos
 * @brief lee un archivo formato EXT
 * @param: void* ret: dato a cargar
 * @param: int id: numero de archivo
 * @param: int retSize: tamaño del dato
 */
void FileManager::readFile(void* ret, std::string name, int offset, int dataSize) {//T(11+6i)
    if(offset>-1){
        if(name.length()){
            std::ifstream inFile(PathConstants::PROJECT_PATH+name+PathConstants::EXT, std::ios::binary);
            inFile.seekg(offset);
            inFile.read(static_cast<char*>(ret),dataSize);
            inFile.close();
        }else{
            printf(NULL_PARAMETER);
            throw NULL_PARAMETER_CODE;
        }
    }else{
        printf(OFFSET_OUT_OF_BOUND);
        throw OFFSET_OUT_OF_BOUND_CODE;
    }
}

/** Borra archivo
 * @brief borra un archivo formato EXT
 * @param: int id: numero de archivo
 */
void FileManager::deleteFile(std::string name){
    if(name.length()){
        remove((PathConstants::PROJECT_PATH+name+PathConstants::EXT).c_str());
    }else{
        printf(NULL_PARAMETER);
        throw NULL_PARAMETER_CODE;
    }
}