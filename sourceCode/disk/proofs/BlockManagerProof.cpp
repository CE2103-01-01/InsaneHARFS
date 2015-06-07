//
// Created by roberto on 06/06/15.
//

#include "BlockManagerProof.h"

void blockManagerProof(){
    int blocks = 10;
    BlockManager* manager = static_cast<BlockManager*>(malloc(sizeof(BlockManager)));
    new(manager) BlockManager("disk",blocks);
    std::cout << "SE HAN CREADO " << blocks << " BLOQUES"<<std::endl;
    manager->print();

    for(long i = 0; i < (blocks)*10000000000000000/2; i+=10000000000000000) {
        std::cout << "SE AGREGARA DATO " << i << std::endl;
        manager->addBlock(std::addressof(i),sizeof(i));
        manager->print();
    }

    printf("SE ELIMINARA BLOQUE 0\n");
    manager->deleteBlock(0);
    manager->print();
    printf("SE ELIMINARA BLOQUE 2\n");
    manager->deleteBlock(2);
    manager->print();
    printf("SE ELIMINARA BLOQUE 4\n");
    manager->deleteBlock(4);
    manager->print();
    printf("SE AGREGARA DATO 10\n");
    manager->addBlock(std::addressof(blocks),sizeof(blocks));
    manager->print();

    long* tmp = static_cast<long*>(malloc(sizeof(long)));
    manager->searchBlock(tmp,6,NULL);
    std::cout << "SE CARGA DATO QUE INICIA EN BLOQUE 6: "<< *tmp << std::endl;
    manager->searchBlock(tmp,8,NULL);
    std::cout << "SE CARGA DATO QUE INICIA EN BLOQUE 8: "<< *tmp << std::endl;
    free(manager);
}