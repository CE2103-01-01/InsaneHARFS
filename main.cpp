#include <iostream>
#include <stdio.h>
#include "models/Pointer.h"

using namespace std;

int main() {
    Pointer<int> number = malloc(sizeof(int));
    *number = 2;
    cout << "Hello, World!" << *number<<endl;
    number.Free();
    return 0;
}
