#include <signal.h>
#include "config/diskConfiguration.h"
#include "proofs/BlockManagerProof.h"
#include "network/TCPServer.h"
#include <math.h>
#include <thread>

#define CAUGHT_SIGNAL "Caught signal %d\n"
#define USAGE_MSG "Usage : harfs-disk --config res/disk_config.cfg \n"
#define CONFIG "--config"

TCPServer *server;
void initServer()
{
    server =TCPServer::getInstance();
}
// Define the function to be called when ctrl-c (SIGINT) signal is sent to process
void signal_callback_handler(int signum) {
    printf(CAUGHT_SIGNAL,signum);
    // Cleanup and close up stuff here
    free(Configuration::getInstance());
    // Terminate program
    exit(signum);
}

unsigned long aa(int order, int floor){
    return pow(order+1,floor) - 1;
}

/**
 * Usage: goto edit configurations and then program arguments:
 * insert this --config res/disk_config.cfg
 */
int main(int argc, char* argv[]) {
    // Register signal and signal handler
    signal(SIGINT, signal_callback_handler);
    signal(SIGTERM, signal_callback_handler);
    signal(SIGABRT, signal_callback_handler);
    //Handle Configuration
    if (argc!=3||strcmp(argv[1], CONFIG)) {
        printf(USAGE_MSG);
        abort();
    } else Configuration::initializeAndGetInstance(argv[2]);
    thread serverThread (initServer);

    serverThread.join();
    free(Configuration::getInstance());// Garbage Collection!
    return 0;
}