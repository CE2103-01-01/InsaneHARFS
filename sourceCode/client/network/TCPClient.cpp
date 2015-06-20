//
// Created by pablo on 06/06/15.
//

#include <unistd.h>
#include "TCPClient.h"



TCPClient::TCPClient() {
    on = true;
    std::cout << "Connecting: " << Configuration::getInstance()->getControllerIP() << ':' << Configuration::getInstance()->getControllerPort() << std::endl;
    LOOP:
    try {
        // Establish connection with the echo server
        sock = new TCPSocket(Configuration::getInstance()->getControllerIP(), Configuration::getInstance()->getControllerPort());

        std::cout << "Connected: " << Configuration::getInstance()->getControllerIP() << ':' << Configuration::getInstance()->getControllerPort() << std::endl;

        // Send the string to the echo server
        //              1234567890123456789012345678901234
        string hello = "12345678901234567890123456789012345678901234567890/53";
        sock->send(hello.c_str() , hello.length()+1);



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
        char echoBuffer[RCVBUFSIZE+1];
        string message;
        int bytesReceived = 0;              // Bytes read on each recv()
        int totalBytesReceived = 0;         // Total bytes read
        while ((bytesReceived = sock->recv(echoBuffer, RCVBUFSIZE)) > 0)// Zero means end of transmission
        {
            totalBytesReceived += bytesReceived;     // Keep tally of total bytes
            echoBuffer[bytesReceived]='\0';
            message.append(echoBuffer);
            if(echoBuffer[bytesReceived-1]=='\0') break;
        }
        std::cout << "Message Received: " << message<<std::endl;

    } catch(SocketException &e) {
        cerr << e.what() << endl;
        exit(1);
    }
}

void TCPClient::send(const void *buffer, int bufferLen) {
    sock->send(buffer,bufferLen);
}


TCPClient::~TCPClient() {
    sock->~Socket();
}

