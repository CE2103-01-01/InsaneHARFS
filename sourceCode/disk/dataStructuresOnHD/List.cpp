//
// Created by roberto on 05/06/15.
//

#include "List.h"

/**@brief construye lista en disco
 * @param std::string pathParam: sitio donde se guardara la lista
 */
List::List(std::string pathParam, int dataSizeParam, int keySizeParam){
    if(pathParam.length() && dataSizeParam){
        keySize = keySizeParam;
        dataSize = dataSizeParam;
        path = pathParam;
        head = -1;
        tail = -1;
        firstEmpty = -1;
        FileManager::createFile(path, LIST_HEADER_LENGHT + LIST_NODE_LENGHT_WITHOUT_DATA + dataSize);
        //Escribe tamano de dato y tamano de clave, como son constantes no se incluyen en el update
        FileManager::writeFile(std::addressof(keySize), path, POSITION_OF_KEY_SIZE_ON_HEADER*LIST_HEADER_MEMBER_LENGHT,
                               LIST_HEADER_MEMBER_LENGHT);
        FileManager::writeFile(std::addressof(dataSize), path, POSITION_OF_DATA_SIZE_ON_HEADER*LIST_HEADER_MEMBER_LENGHT,
                               LIST_HEADER_MEMBER_LENGHT);
        updateHeader();
    }else{
        printf(NULL_PARAMETER);
        throw NULL_PARAMETER_CODE;
    }
}

/**@brief actualiza el header
 */
void List::updateHeader() {
    FileManager::writeFile(std::addressof(head), path, POSITION_OF_HEAD_ON_HEADER*LIST_HEADER_MEMBER_LENGHT,
                           LIST_HEADER_MEMBER_LENGHT);
    FileManager::writeFile(std::addressof(tail), path, POSITION_OF_TAIL_ON_HEADER*LIST_HEADER_MEMBER_LENGHT,
                           LIST_HEADER_MEMBER_LENGHT);
    FileManager::writeFile(std::addressof(firstEmpty), path, POSITION_OF_FIRST_EMPTY_ON_HEADER*LIST_HEADER_MEMBER_LENGHT,
                           LIST_HEADER_MEMBER_LENGHT);
    FileManager::writeFile(std::addressof(lenght), path, POSITION_OF_LENGHT_ON_HEADER*LIST_HEADER_MEMBER_LENGHT,
                           LIST_HEADER_MEMBER_LENGHT);
}

/**@brief busca un dato
 * @param void* key: clave de busqueda
 * @return void*: dato
 */
void* List::search(void* key){
    return search(getOffset(key));
}

/**@brief busca un dato
 * @param void* key: clave de busqueda
 * @return int offset
 */
int List::getOffset(void* key){
    if(key){
        //Se crea el buffer para el iterador
        int* tmp = static_cast<int*>(malloc(sizeof(int)));
        *tmp = head;
        //Crea el buffer de la llave
        void* readedKey = malloc(dataSize);
        while(*tmp!=-1){
            //Carga la llave
            FileManager::readFile(readedKey,path,LIST_HEADER_LENGHT+*tmp*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                 +LIST_NODE_LENGHT_WITHOUT_DATA, keySize);
            //Compara la llave leida con la buscada
            if(compare(readedKey,key,keySize)){
                int toRet  = *tmp;
                //Libera memoria
                free(readedKey);
                free(tmp);
                //Retorna el buffer
                return toRet;
            }
            //lee siguiente
            FileManager::readFile(tmp,path,LIST_HEADER_LENGHT+*tmp*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize),LIST_NODE_MEMBER_LENGHT);
        }
        //Maneja error y libera memoria
        free(readedKey);
        free(tmp);
        printf(KEY_NOT_FOUND);
        throw OFFSET_OUT_OF_BOUND_CODE;
    }else{
        printf(NULL_PARAMETER);
        throw NULL_PARAMETER_CODE;
    }
}

/**@brief busca un dato
 * @param int offset: posicion
 * @return void*: dato
 */
void* List::search(int offset){
    //Comprueba que el offset sea valido
    if(offset > -1){
        //Si son iguales crea un buffer donde cargara el dato
        void* toRet = malloc(dataSize);
        //Lee el dato a retornar
        FileManager::readFile(toRet,path,LIST_HEADER_LENGHT+offset*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                         +LIST_NODE_LENGHT_WITHOUT_DATA+keySize, dataSize);
        //Retorna el buffer
        return toRet;
    }//Maneja error
    else {
        printf(OFFSET_OUT_OF_BOUND);
        throw OFFSET_OUT_OF_BOUND_CODE;
    }
}

/**@brief compara dos dato
 * @param void*: puntero a posicion en la lista, contiene el numero de nodo
 * @return Pointer: puntero a posicion del dato en otro archivo
 */
bool List::compare(void* dataOne, void* dataTwo, int dataLenght){
    if(dataOne && dataTwo && dataLenght){
        for(int i = 0; i < dataLenght; i++) if(*static_cast<char*>(dataOne+i)!=*static_cast<char*>(dataTwo+i)) return false;
        return true;
    }else{
        printf(NULL_PARAMETER);
        throw NULL_PARAMETER_CODE;
    }
}

/**@brief inserta un dato
 * @param void* toInsert: dato
 * @param void* key: llave de busqueda
 * @return int
 */
int List::insertData(void* toInsert, void* key){
    if(toInsert && key){
        int id;
        //Si la lista no esta vacia
        if(head != -1 && tail != -1){
            int toWriteOnNext;
            if(firstEmpty!=-1) toWriteOnNext = firstEmpty;
            else toWriteOnNext = lenght;
            //Escribe siguiente a la cola
            FileManager::writeFile(std::addressof(toWriteOnNext), path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                                        + POSITION_OF_NEXT_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            //Escribe el anterior nueva a la cola
            FileManager::writeFile(std::addressof(tail), path, LIST_HEADER_LENGHT + toWriteOnNext*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                                        + POSITION_OF_PREVIOUS_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            tail = toWriteOnNext;
            int tmp = -1;
            //Setea en -1 el siguiente y siguiente vacio
            FileManager::writeFile(std::addressof(tmp), path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                              + POSITION_OF_NEXT_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            FileManager::writeFile(std::addressof(tmp), path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                              + POSITION_OF_NEXT_EMPTY_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            //Escribe el dato
            FileManager::writeFile(key, path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                              + LIST_NODE_LENGHT_WITHOUT_DATA, keySize);
            FileManager::writeFile(toInsert, path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                   + LIST_NODE_LENGHT_WITHOUT_DATA+keySize, dataSize);
            id = tail;
        }//Si existe la cabeza
        else if(head != -1){
            int tmp = -1;
            tail = 1;
            //Coloca a la cola como siguiente de la cabeza
            FileManager::writeFile(std::addressof(tail), path, LIST_HEADER_LENGHT + head*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                               + POSITION_OF_NEXT_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            //Setea en -1 el siguiente y siguiente vacio
            FileManager::writeFile(std::addressof(tmp), path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                              + POSITION_OF_NEXT_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            FileManager::writeFile(std::addressof(head), path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                              + POSITION_OF_PREVIOUS_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            FileManager::writeFile(std::addressof(tmp), path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                              + POSITION_OF_NEXT_EMPTY_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            //Escribe el dato
            FileManager::writeFile(key, path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                              + LIST_NODE_LENGHT_WITHOUT_DATA, keySize);
            FileManager::writeFile(toInsert, path, LIST_HEADER_LENGHT + tail*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                   + LIST_NODE_LENGHT_WITHOUT_DATA+keySize, dataSize);
            id = tail;
        }//Si la lista esta vacia
        else{
            int tmp = -1;
            //Setea en -1 el siguiente y siguiente vacio y escribe el dato
            FileManager::writeFile(std::addressof(tmp), path, LIST_HEADER_LENGHT + POSITION_OF_NEXT_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            FileManager::writeFile(std::addressof(tmp), path, LIST_HEADER_LENGHT + POSITION_OF_PREVIOUS_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            FileManager::writeFile(std::addressof(tmp), path, LIST_HEADER_LENGHT + POSITION_OF_NEXT_EMPTY_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
            FileManager::writeFile(key, path, LIST_HEADER_LENGHT + LIST_NODE_LENGHT_WITHOUT_DATA, keySize);
            FileManager::writeFile(toInsert, path, LIST_HEADER_LENGHT + LIST_NODE_LENGHT_WITHOUT_DATA+keySize, dataSize);
            head = 0;
            id = head;
        }
        lenght++;
        updateHeader();
        return id;
    }else{
        printf(NULL_PARAMETER);
        throw NULL_PARAMETER_CODE;
    }
}

/**@brief
 * @param Pointer
 */
void List::deleteData(void* key){
    //Busca el offset
    int offset = getOffset(key);
    //Lee los enlaces  | anterior | siguiente |
    int* links = static_cast<int*>(malloc(2 * sizeof(int)));
    FileManager::readFile(links, path, LIST_HEADER_LENGHT + offset*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                       + POSITION_OF_PREVIOUS_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
    FileManager::readFile(links+1, path, LIST_HEADER_LENGHT + offset*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                       + POSITION_OF_NEXT_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
    //Escribe el siguiente vacio y lo actualiza
    FileManager::writeFile(std::addressof(firstEmpty), path,
                           LIST_HEADER_LENGHT + offset*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                            + POSITION_OF_NEXT_EMPTY_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
    //Si los enlaces no son nulos
    if(*(links) > -1 && *(links+1) > -1){
        FileManager::writeFile(links, path, LIST_HEADER_LENGHT + *(links+1)*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                             + POSITION_OF_PREVIOUS_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
        FileManager::writeFile(links+1, path, LIST_HEADER_LENGHT + *(links)*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                             + POSITION_OF_NEXT_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
    }//Si es la cola
    else if(*(links) > -1){
        int tmp = -1;
        FileManager::writeFile(std::addressof(tmp), path, LIST_HEADER_LENGHT + *(links)*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                            + POSITION_OF_NEXT_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
        tail = *links;
    }//Si es la cabeza
    else if(*(links + 1) > -1){
        int tmp = -1;
        FileManager::writeFile(std::addressof(tmp), path, LIST_HEADER_LENGHT + *(links)*(LIST_NODE_LENGHT_WITHOUT_DATA+keySize+dataSize)
                                                          + POSITION_OF_PREVIOUS_ON_NODE*LIST_NODE_MEMBER_LENGHT, LIST_NODE_MEMBER_LENGHT);
        head = *(links+1);
    }else{
        head = 0;
    }
    lenght--;
    firstEmpty = offset;
    updateHeader();
}