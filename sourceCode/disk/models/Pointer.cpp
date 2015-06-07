//
// Created by roberto on 05/06/15.
//

#include "Pointer.h"

/**@brief constructor
 * @param int id
 */
Pointer::Pointer(int idParam){
    id = idParam;
}

/**@brief destructor
 */
Pointer::~Pointer(){
    data = 0;
    id = 0;
}

/**@brief operador de asignacion
 * @param int id
 */
Pointer Pointer::operator =(int idParam){ 
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
 * @param int id
 * @return bool
 */
bool Pointer::operator ==(int idParam){ 
    return id == idParam; 
}

/**@brief operador de diferencia
 * @param int id
 * @return bool
 */
bool Pointer::operator !=(int idParam){ 
    return id != idParam; 
}

/**@brief operador de menor igual
 * @param int id
 * @return bool
 */
bool Pointer::operator <=(int  idParam){ 
    return id <= idParam; 
}

/**@brief operador de mayor igual
 * @param int id
 * @return bool
 */
bool Pointer::operator >=(int  idParam){ 
    return id >= idParam; 
}

/**@brief operador de menor
 * @param int id
 * @return bool
 */
bool Pointer::operator <(int  idParam){ 
    return id < idParam; 
}

/**@brief operador de mayor
 * @param int id
 * @return bool
 */
bool Pointer::operator >(int  idParam){ 
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
    return data;        //Todo: modificar
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
 * @param intother
 * @return Pointer
 */
Pointer Pointer::operator -(int other){
    return id - other;
}

/**@brief operador de suma
 * @param int other
 * @return Pointer
 */
Pointer Pointer::operator +(int other){
    return id + other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator *(int other){
    return id * other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator /(int other){
    return id / other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator -=(int other){
    return id -= other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator +=(int other){
    return id += other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator /=(int other){
    return id /= other;
}

/**@brief operador de disminucion
 * @param Pointer other
 * @return Pointer
 */
Pointer Pointer::operator *=(int other){
    return id *= other;
}
