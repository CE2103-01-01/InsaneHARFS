#include <iostream>
#include "models/Pointer.h"
#include "config/Configuration.h"

using namespace std;

int main() {
    cout<<Configuration::initializeAndGetInstance("res/config.cfg")->getPath()<<endl;
    cout<<Configuration::getInstance()->getSharedSecret()<<endl;



    Pointer<int> number = malloc(sizeof(int));
    *number = 2;
    cout << "Number: " << *number<<endl;
    number.Free();
    return 0;
}
