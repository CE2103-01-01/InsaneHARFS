#include <signal.h>
#include "config/diskConfiguration.h"
#include "../disk/managers/BlockManager.h"
#include "proofs/FileManagerProof.h"

#define CAUGHT_SIGNAL "Caught signal %d\n"
#define USAGE_MSG "Usage : harfs-disk --config res/disk_config.cfg \n"
#define CONFIG "--config"

// Define the function to be called when ctrl-c (SIGINT) signal is sent to process
void signal_callback_handler(int signum) {
    printf(CAUGHT_SIGNAL,signum);
    // Cleanup and close up stuff here
    free(Configuration::getInstance());
    // Terminate program
    exit(signum);
}

/**
 * Usage: goto edit configurations and then program arguments:
 * insert this --config res/disk_config.cfg
 */
int main(int argc, char* argv[]) {
    // Register signal and signal handler
    signal(SIGINT, signal_callback_handler);
    signal(SIGABRT, signal_callback_handler);
    //Handle Configuration
    if (argc!=3||strcmp(argv[1], CONFIG)) {
        printf(USAGE_MSG);
        abort();
    } else Configuration::initializeAndGetInstance(argv[2]);

    /** PRUEBAS **/
    int blocks = 10;
    BlockManager* manager = static_cast<BlockManager*>(malloc(sizeof(BlockManager)));
    new(manager) BlockManager("disk",blocks);
    std::cout << "SE HAN CREADO " << blocks << " BLOQUES"<<std::endl;
    manager->print();

    for(int i = 0; i < blocks; i++) {
        std::cout << "SE AGREGARA DATO " << i << std::endl;
        manager->addBlock(std::addressof(i),sizeof(i));
        manager->print();
    }

    printf("SE ELIMINARA BLOQUE 1\n");
    manager->deleteBlock(1);
    manager->print();
    printf("SE ELIMINARA BLOQUE 3\n");
    manager->deleteBlock(3);
    manager->print();
    printf("SE ELIMINARA BLOQUE 6\n");
    manager->deleteBlock(6);
    manager->print();
    printf("SE AGREGARA DATO 10\n");
    manager->addBlock(std::addressof(blocks),sizeof(blocks));
    manager->print();
    free(manager);
    /** ~PRUEBAS **/

    free(Configuration::getInstance());// Garbage Collection!
    return 0;
}