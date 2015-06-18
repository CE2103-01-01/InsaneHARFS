//
// Created by pablo on 06/06/15.
//

#include <chrono>
#include <thread>
#include <unistd.h>
#include "TCPClient.h"



TCPClient::TCPClient(string ip, unsigned short &port) {
    on = true;
    std::cout << "Connecting: " << ip << ':' << port << std::endl;
    LOOP:
    try {
        // Establish connection with the echo server
        sock = new TCPSocket(ip,port);
        std::cout << "Connected: " << ip << ':' << port << std::endl;
        // Send the string to the echo server
        //              1234567890123456789012345678901234
        string hello = "helloworld";
        sock->send(hello.c_str() , 10);

        while(on)
        {
            receive();
        }


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
