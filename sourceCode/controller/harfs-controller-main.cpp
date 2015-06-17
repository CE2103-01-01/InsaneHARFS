//
// Created by pablo on 06/06/15.
//

#include <iostream>
#include <signal.h>
#include <string.h>
#include <thread>
#include "config/controllerConfiguration.h"
#include "network/TCPServer.h"

#define CAUGHT_SIGNAL "Caught signal %d\n"
#define USAGE_MSG "Usage : harfs-disk --config res/controller_config.cfg \n"
#define CONFIG "--config"




using namespace std;


TCPServer *server;

void initServer()
{
    server = new TCPServer();
}

// Define the function to be called when ctrl-c (SIGINT) signal is sent to process
void signal_callback_handler(int signum) {
    printf(CAUGHT_SIGNAL,signum);
    // Cleanup and close up stuff here
    free(Configuration::getInstance());
    delete server;
    // Terminate program
    exit(signum);
}

/**
 * Usage: goto edit configurations and then program arguments:
 * insert this --config res/controller_config.cfg
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

    //Thread for server
    thread serverThread (initServer);


    serverThread.join();

    // Garbage Collection!
    free(Configuration::getInstance());
    delete server;

    return 0;

}
