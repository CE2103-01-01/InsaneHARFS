//
// Created by pablo on 06/06/15.
//

#include <iostream>
#include <signal.h>
#include <string.h>
#include "config/controllerConfiguration.h"

using namespace std;


void signal_callback_handler(int signum);
/**
 * Prints intructions of use
 */
void printUsage()
{
    cerr<<"Usage : harfs-controller --config res/controller_config.cfg"<<endl;

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
    if (argc!=3||strcmp(argv[1], "--config"))
    {
        printUsage();
        abort();
    }
    else Configuration::initializeAndGetInstance(argv[2]);




    delete Configuration::getInstance();// Garbage Collection!
    return 0;
}


// Define the function to be called when ctrl-c (SIGINT) signal is sent to process
void signal_callback_handler(int signum)
{
    printf("Caught signal %d\n",signum);
    delete Configuration::getInstance();
    // Cleanup and close up stuff here

    // Terminate program
    exit(signum);
}
