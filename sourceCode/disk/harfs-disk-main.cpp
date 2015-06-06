#include <signal.h>
#include "config/diskConfiguration.h"
#include "../disk/managers/BlockManager.h"

using namespace PathConstants;

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
    }
    else Configuration::initializeAndGetInstance(argv[2]);

    /** PRUEBAS **/
    BlockManager* manager = static_cast<BlockManager*>(malloc(sizeof(BlockManager(PROJECT_PATH+"disk"+EXT,50))));
    new(manager) BlockManager(PROJECT_PATH+"disk"+EXT,50);
    /** ~PRUEBAS **/

    free(Configuration::getInstance());// Garbage Collection!
    return 0;
}