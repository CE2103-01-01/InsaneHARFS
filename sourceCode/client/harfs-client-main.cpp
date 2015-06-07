//
// Created by pablo on 06/06/15.
//

#include <iostream>
#include <signal.h>
#include <thread>
#include "config/clientConfiguration.h"
#include "network/TCPClient.h"

#define CAUGHT_SIGNAL "Caught signal %d\n"
#define USAGE_MSG "Usage : harfs-disk --config res/client_config.cfg \n"
#define CONFIG "--config"

using namespace std;
TCPClient *client;
void initClient()
{
    client = new TCPClient();
}
// Define the function to be called when ctrl-c (SIGINT) signal is sent to process
void signal_callback_handler(int signum) {
    printf(CAUGHT_SIGNAL,signum);
    // Cleanup and close up stuff here

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

    //Thread for server
    thread serverThread (initClient);


    serverThread.join();

    // Garbage Collection!
    free(Configuration::getInstance());
    delete client;

    return 0;

}


