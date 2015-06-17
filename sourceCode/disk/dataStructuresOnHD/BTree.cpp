//
// Created by roberto on 14/06/15.
//

#include "BTree.h"

/**@brief contruye un arbol b en disco con los atributos por defecto
 */
BTree::BTree(){
    keyLenght = DEFAULT_KEY_LENGHT;
    order = DEFAULT_ORDER;
    firstEmpty = -1;
    lenght = 0;
    init(DEFAULT_NAME);
}

/**@brief construye un arbol b a gusto del usuario
 * @param long keyLenghtParam: tamano que se reservara para cada clave
 * @param long orderParam: numero de claves por nodos
 */
BTree::BTree(long keyLenghtParam, long orderParam){
    keyLenght = keyLenghtParam;
    order = orderParam;
    firstEmpty = -1;
    lenght = 0;
    init(DEFAULT_NAME);
}

/**@brief construye un arbol b a gusto del usuario
 * @param std::string name: nombre de los archivos
 * @param long keyLenghtParam: tamano que se reservara para cada clave
 * @param long orderParam: numero de claves por nodos
 */
BTree::BTree(std::string name, long keyLenghtParam, long orderParam){
    keyLenght = keyLenghtParam;
    order = orderParam;
    firstEmpty = -1;
    lenght = 0;
    init(name);
}

/**@brief reconstruye un arbol b a partir de sus archivos
 * @param std::string headerPathParam: ruta del header (.header)
 * @param std::string dataPathparam: ruta de los nodos (.data)
 */
BTree::BTree(std::string headerPathParam, std::string dataPathParam){
    headerPath = headerPathParam;
    dataPath = dataPathParam;
    readHeader();
}

/**@brief lee las variables necesarias del header
 */
void BTree::readHeader() {
    FileManager::readFile(std::addressof(order),headerPath,ORDER_ON_HEADER*HEADER_OFFSET,sizeof(order));
    FileManager::readFile(std::addressof(keyLenght),headerPath,KEY_LENGHT_ON_HEADER*HEADER_OFFSET,sizeof(keyLenght));
    FileManager::readFile(std::addressof(lenght),headerPath,LENGHT_ON_HEADER*HEADER_OFFSET,sizeof(lenght));
    FileManager::readFile(std::addressof(firstEmpty),headerPath,FIRST_EMPTY_ON_HEADER*HEADER_OFFSET,sizeof(firstEmpty));
}

/**@brief crea los archivos y los inicializa
 * @param std::string name: nombre que tendran los archivos .header y .data
 */
void BTree::init(std::string name) {
    //Crea las rutas
    headerPath = PathConstants::PROJECT_PATH + name + PathConstants::HEADER_EXT;
    dataPath = PathConstants::PROJECT_PATH + name + PathConstants::DATA_EXT;
    //Crea el header
    FileManager::createFile(headerPath, HEADER_LENGHT);
    FileManager::writeFile(std::addressof(order),headerPath,ORDER_ON_HEADER*HEADER_OFFSET,sizeof(order));
    FileManager::writeFile(std::addressof(keyLenght),headerPath,KEY_LENGHT_ON_HEADER*HEADER_OFFSET,sizeof(keyLenght));
    updateHeader();
    //Crea el primer nodo
    FileManager::createFile(dataPath,NODE_OFFSET+NODE_ELEMENT_LENGHT+order*(keyLenght+NODE_ELEMENT_LENGHT));
    //TODO
}

/**@brief actualiza la longitud y el primer vacio
 */
void BTree::updateHeader() {
    FileManager::writeFile(std::addressof(lenght),headerPath,LENGHT_ON_HEADER*HEADER_OFFSET,sizeof(lenght));
    FileManager::writeFile(std::addressof(firstEmpty),headerPath,FIRST_EMPTY_ON_HEADER*HEADER_OFFSET,sizeof(firstEmpty));
}

/**@brief inserta un elemento al arbol
 * @param void* key: clave a insertar
 * @param long pointer: puntero con al dato representado por la clave
 */
void BTree::insertKey(void* key, long pointer){

}

/**@brief busca un elemento en el arbol
 * @param void* key: clave sobre la que se operara
 */
long BTree::searchKey(void* key){

}

/**@brief elimina un elemento del arbol
 * @param void* key: clave sobre la que se operara
 */
void BTree::deleteKey(void* key){

}