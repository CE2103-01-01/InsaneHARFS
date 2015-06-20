//
// Created by pablo on 06/06/15.
//

#include <unistd.h>
#include "TCPClient.h"

TCPClient *TCPClient::singleton = NULL;

TCPClient::TCPClient() {
    initConnection();
}

void TCPClient::initConnection() {
    on = true;
    cout << "Connecting: " << Configuration::getInstance()->getControllerIP() << ':' << Configuration::getInstance()->getControllerPort() << endl;
    LOOP:
    try {
        // Establish connection with the echo server
        sock = new TCPSocket(Configuration::getInstance()->getControllerIP(), Configuration::getInstance()->getControllerPort());

        cout << "Connected: " << Configuration::getInstance()->getControllerIP() << ':' << Configuration::getInstance()->getControllerPort() << endl;

        // Send the string to the echo server


    } catch(SocketException &e) {
        usleep(SLEEP);
        goto LOOP;
    }
}

void TCPClient::receive() {
    char echoBuffer[RCVBUFSIZE+1];
    string message;
    int bytesReceived = 0;              // Bytes read on each recv()
    int totalBytesReceived = 0;         // Total bytes read
    while(on)
    try {

        while ((bytesReceived = sock->recv(echoBuffer, RCVBUFSIZE)) > 0)// Zero means end of transmission
        {
            totalBytesReceived += bytesReceived;     // Keep tally of total bytes
            echoBuffer[bytesReceived]='\0';
            message.append(echoBuffer);
            if(echoBuffer[bytesReceived-1]=='\0') break;
        }

        if (sock->send(message.c_str(),message.length()+1)==0)
        {
            sock->~Socket(); //Closed Socket
            std::cout << "Disconnected" << std::endl;
            initConnection();
        }
        std::cout << "Message Received: " << message<<std::endl;

    } catch(SocketException &e) {
        cerr << e.what() << endl;
        exit(1);
    }
}

void TCPClient::send(const void *buffer, int bufferLen) {
    std::cout << "Sending: " << static_cast<const char*>(buffer) << std::endl;
    sock->send(buffer,bufferLen);
}


TCPClient::~TCPClient() {
    sock->~Socket();
}

TCPClient *TCPClient::getInstance() {
    if(singleton==NULL){
        singleton = new TCPClient();
    }
    return singleton;
}
