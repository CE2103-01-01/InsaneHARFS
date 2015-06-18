//
// Created by roberto on 17/06/15.
//

#include "Buffer.h"

/**@brief inicializa un buffer
 * @param int sizeParam: tamano del dato
 * @param void* dataParam: bytes a guardar
 */
Buffer::Buffer(int sizeParam, void* dataParam){
    size = sizeParam;
    data = dataParam;
}

/**@brief copia un buffer
 * @param const Buffer& other: buffer a copia
 */
Buffer::Buffer(const Buffer& other){
    copy(other);
}

/**@brief copia un buffer
 * @param const Buffer& other: buffer a copia
 */
void Buffer::operator =(const Buffer& other){
    copy(other);
}

/**@brief libera el espacio
 */
Buffer::~Buffer(){
    free(data);
}

/**@brief copia un buffer
 * @param const Buffer& other: buffer a copia
 */
void Buffer::copy(const Buffer& other) {
    size = other.size;
    if(data) free(data);
    data = malloc(other.size);
    memcpy(data,other.data,size);
}

/**@brief accede a una seccion del dato
 * @param int offset byte a direccionar
 * @return void* seccion del dato
 */
void* Buffer::get(int offset){
    if(offset<size) return data+offset;
    else{
        printf(OFFSET_OUT_OF_BOUND);
        throw OFFSET_OUT_OF_BOUND_CODE;
    }
}

/**@brief cambia el contenido del buffer
 * @param int sizeParam: nuevo tamano
 * @param void* dataParam: nuevo dato
 */
void Buffer::changeContent(int sizeParam, void* dataParam){
    size = sizeParam;
    if(data) free(data);
    data = dataParam;
}