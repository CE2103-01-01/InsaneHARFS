#include <iostream>
#include "src/models/Pointer.h"
#include "src/config/Configuration.h"

using namespace std;
/**
 * Usage: goto edit configurations and then program arguments:
 * insert this --config res/config.cfg
 */
int main(int argc, char* argv[]) {
    if (argc!=3)
    {
        cerr<<"Usage : harfs-disk --config res/config.cfg"<<endl;
    }
    cout<<"Path to file: "<<Configuration::initializeAndGetInstance(argv[2])->getPath()<<endl;
    cout<<"SharedSecret: "<<Configuration::getInstance()->getSharedSecret()<<endl;
    cout<<"Port: "<<Configuration::getInstance()->getPort()<<endl;
    cout<<"Disk Size: "<<Configuration::getInstance()->getDiskSize()<<endl;



    Pointer<int> number = malloc(sizeof(int));
    *number = 2;
    cout << "Number from Pointer: " << *number<<endl;
    number.Free();
    return 0;
}
