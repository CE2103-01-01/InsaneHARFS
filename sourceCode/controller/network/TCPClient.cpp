//
// Created by pablo on 06/06/15.
//

#include <chrono>
#include <thread>
#include <unistd.h>
#include "TCPClient.h"

TCPClient *TCPClient::singleton = NULL;

TCPClient::TCPClient(string ip, unsigned short &port) {
    initConnection(ip,port);
}

void TCPClient::initConnection(string ip, unsigned short &port) {
    on = true;
    cout << "Connecting: " << ip << ':' << port << endl;
    LOOP:
    try {
        // Establish connection with the echo server
        sock = new TCPSocket(ip, port);

        cout << "Connected: " << ip << ':' << port << endl;

        // Send the string to the echo server


    } catch(SocketException &e) {
        usleep(SLEEP);
        goto LOOP;
    }
}



void TCPClient::receive() {
    try {
    char echoBuffer[RCVBUFSIZE + 1];    // Buffer for echo string + \0
    int bytesReceived = 0;              // Bytes read on each recv()
    int totalBytesReceived = 0;         // Total bytes read
// Receive the same string back from the server
    //cout << "Received: ";               // Setup to print the echoed string
    while (totalBytesReceived < 10) {
        // Receive up to the buffer size bytes from the sender
        if ((bytesReceived = (sock->recv(echoBuffer, RCVBUFSIZE))) <= 0) {
            cerr << "Unable to read";
            exit(1);
        }
        totalBytesReceived += bytesReceived;     // Keep tally of total bytes
        echoBuffer[bytesReceived] = '\0';        // Terminate the string!
        //cout << echoBuffer;                      // Print the echo buffer
    }
    //cout << endl;

    } catch(SocketException &e) {
        cerr << e.what() << endl;
        exit(1);
    }
}


TCPClient::~TCPClient() {
    sock->~Socket();
}

TCPClient *TCPClient::initialize(string ip, unsigned short &port) {
    if(singleton==NULL){
        singleton = new TCPClient(ip,port);
    }
}

TCPClient *TCPClient::getInstance() {
    if(!singleton) cerr<<"Please initialize"<<endl;
    return singleton;
}