#include <iostream>
#include "models/pointer/MemoryPointer.h"

using namespace std;

int main() {
    MemoryPointer<int> number = malloc(sizeof(int));
    number.set(2);
    cout << "Hello, World!" << *number.get()<<endl;
    return 0;
}