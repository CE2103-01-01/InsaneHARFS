//
// Created by roberto on 05/06/15.
//

#include "List.h"

/**@brief construye lista en disco
 * @param std::string pathParam: sitio donde se guardara la lista
 */
List::List(std::string pathParam){
    path = pathParam;
    std::fstream file(path.c_str(),std::ios::binary);
    for(int i = 0; i<HEADER_LENGHT; i++){
        file.write(0,1);
    }
    file.close();
}

/**@brief busca un dato
 * @param Pointer: puntero a posicion en la lista, contiene el numero de nodo
 * @return Pointer: puntero a posicion del dato en otro archivo
 */
Pointer List::search(Pointer toGet){

}

/**@brief inserta un dato
 * @param Pointer
 */
void List::insertData(Pointer toInsert){

}

/**@brief
 * @param Pointer
 */
void List::deleteData(Pointer toDelete){

}