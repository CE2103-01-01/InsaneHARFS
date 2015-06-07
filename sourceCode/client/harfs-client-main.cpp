//
// Created by pablo on 06/06/15.
//

#include <iostream>
#include <signal.h>

#define CAUGHT_SIGNAL "Caught signal %d\n"
#define USAGE_MSG "Usage : harfs-disk --config res/client_config.cfg \n"
#define CONFIG "--config"

using namespace std;


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

    return 0;

}


