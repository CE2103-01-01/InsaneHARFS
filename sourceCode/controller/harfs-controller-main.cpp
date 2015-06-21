//
// Created by pablo on 06/06/15.
//

#include <iostream>
#include <signal.h>
#include <string.h>
#include <thread>
#include "config/controllerConfiguration.h"
#include "network/TCPServer.h"
#include "network/TCPClient.h"
#include "models/Bridge.h"

#define CAUGHT_SIGNAL "Caught signal %d\n"
#define USAGE_MSG "Usage : harfs-disk --config res/controller_config.cfg \n"
#define CONFIG "--config"



TCPServer *server;
DoubleLinkedList<TCPSocket*> *sockets;
using namespace std;
//Init Single Client
void initClient(string ip, unsigned short port)
{\
    TCPClient::initialize(ip,port);
}
//Init all the clients
void initClients()
{
    thread threads[Configuration::getInstance()->getNumberOfDiks()];
    ipPort * nodes = Configuration::getInstance()->getDiskNodes();
    for (int i = 0; i < Configuration::getInstance()->getNumberOfDiks(); ++i) {
        ipPort ipPort = (*(nodes+i));
        threads[i] = thread(initClient,string(ipPort.ip),ipPort.port);
    }
    for (int j = 0; j < Configuration::getInstance()->getNumberOfDiks(); ++j) {
        threads[j].join();
    }
}

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

    //initialize
    sockets = new DoubleLinkedList<TCPSocket*>();
    Bridge::initialize(sockets);
    //Thread for server
    thread serverThread (initServer);
    thread clientsThread (initClients);


    serverThread.join();

    // Garbage Collection!
    free(Configuration::getInstance());
    delete server;

    return 0;

}
