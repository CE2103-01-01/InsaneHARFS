#include <signal.h>
#include "config/diskConfiguration.h"
#include "proofs/BlockManagerProof.h"
#include <math.h>
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

    /** PRUEBAS **/
    try{
        int* winner = static_cast<int*>(malloc(2*sizeof(int)));
        unsigned long tmp1 = 0;
        for(int i = 3; i<1000; i++){
            for(int j = 0; j<35; j++){
                unsigned long tmp2 = aa(i,j);
                if(tmp2 > tmp1){
                    tmp1 = tmp2;
                    *(winner) = i;
                    *(winner+1) = j;
                    std::cout << tmp2 << std::endl;
                }
            }
        }
        std::cout << *(winner) << std:: endl;
        std::cout << *(winner+1) << std:: endl;
        //blockManagerProof();
    }catch(int exception){
        return exception;
    }
    /** ~PRUEBAS **/

    free(Configuration::getInstance());// Garbage Collection!
    return 0;
}