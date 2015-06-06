//
// Created by roberto on 05/06/15.
//

#include "Pointer.h"

/**@brief constructor
 * @param long id
 */
Pointer::Pointer(long idParam){
    id = idParam;
}

/**@brief destructor
 */
Pointer::~Pointer(){
    data = 0;
    id = 0;
}

/**@brief operador de asignacion
 * @param long id
 */
Pointer Pointer::operator =(long idParam){ 
    id = idParam; 
    return *this;
}

/**@brief operador de asignacion
 * @param const Pointer& other
 */
Pointer Pointer::operator =(const Pointer& other){
    id = other.id;
    data = other.data;
    return *this;
}

/**@brief operador de igualdad
 * @param long id
 * @return bool
 */
bool Pointer::operator ==(long idParam){ 
    return id == idParam; 
}

/**@brief operador de diferencia
 * @param long id
 * @return bool
 */
bool Pointer::operator !=(long idParam){ 
    return id != idParam; 
}

/**@brief operador de menor igual
 * @param long id
 * @return bool
 */
bool Pointer::operator <=(long  idParam){ 
    return id <= idParam; 
}

/**@brief operador de mayor igual
 * @param long id
 * @return bool
 */
bool Pointer::operator >=(long  idParam){ 
    return id >= idParam; 
}

/**@brief operador de menor
 * @param long id
 * @return bool
 */
bool Pointer::operator <(long  idParam){ 
    return id < idParam; 
}

/**@brief operador de mayor
 * @param long id
 * @return bool
 */
bool Pointer::operator >(long  idParam){ 
    return id > idParam; 
}

/**@brief operador de igualdad
 * @param Pointer other
 * @return bool
 */
bool Pointer::operator ==(Pointer  other){ 
    return id == other.id; 
}

/**@brief operador de diferencia
 * @param Pointer other
 * @return bool
 */
bool Pointer::operator !=(Pointer  other){ 
    return id != other.id;
}

/**@brief operador de menor igual
 * @param Pointer other
 * @return bool
 */
bool Pointer::operator <=(Pointer  other){ 
    return id <= other.id; 
}

/**@brief operador de mayor igual
 * @param Pointer other
 * @return bool
 */
bool Pointer::operator >=(Pointer  other){ 
    return id >= other.id; 
}

/**@brief operador de menor
 * @param Pointer other
 * @return bool
 */
bool Pointer::operator <(Pointer  other){ 
    return id < other.id; 
}

/**@brief operador de mayor
 * @param Pointer other
 * @return bool
 */
bool Pointer::operator >(Pointer  other){ 
    return id > other.id; 
}

/**@brief operador de desreferencia
 * @return void*
 */
void* Pointer::operator *(){
    return data;
}

/**@brief operador de resta
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator -(Pointer other){
    return id - other.id;
}

/**@brief operador de suma
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator +(Pointer other){
    return id + other.id;
}

/**@brief operador de multiplicacion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator *(Pointer other){
    return id * other.id;
}

/**@brief operador de division
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator /(Pointer other){
    return id / other.id;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator -=(Pointer other){
    return id -= other.id;
}

/**@brief operador de aumento
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator +=(Pointer other){
    return id += other.id;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator /=(Pointer other){
    return id /= other.id;
}

/**@brief operador de aumento
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator *=(Pointer other){
    return id *= other.id;
}

/**@brief operador de resta
 * @param longother
 * @return Pointer
 */
Pointer Pointer::operator -(long other){
    return id - other;
}

/**@brief operador de suma
 * @param long other
 * @return Pointer
 */
Pointer Pointer::operator +(long other){
    return id + other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator *(long other){
    return id * other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator /(long other){
    return id / other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator -=(long other){
    return id -= other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator +=(long other){
    return id += other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator /=(long other){
    return id /= other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator *=(long other){
    return id *= other;
}
