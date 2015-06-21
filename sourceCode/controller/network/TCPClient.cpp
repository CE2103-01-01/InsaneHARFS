//
// Created by pablo on 06/06/15.
//

#include <chrono>
#include <thread>
#include <unistd.h>
#include "TCPClient.h"
#include "../models/Bridge.h"

TCPClient *TCPClient::singleton = NULL;

TCPClient::TCPClient(string ip, unsigned short &port) {
    initConnection(ip,port);
    iport= ipPort(ip,port);
}

void TCPClient::initConnection(string ip, unsigned short &port) {
    on = true;
    cout << "Connecting: " << ip << ':' << port << endl;
    LOOP:
    try {
        // Establish connection with the echo server
        sock = new TCPSocket(ip, port);

        cout << "Connected: " << ip << ':' << port << endl;
        Bridge::getInstance()->addSocket(sock);
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
            if (message.length()==0) throw (SocketException("Empty Message", true));
            Bridge::getInstance()->sendToUser(message);
            std::cout << "Message Received: " << message<<std::endl;
        } catch(SocketException &e) {
            sock->~Socket(); //Closed Socket
            std::cout << "Disconnected" << std::endl;
            initConnection(iport.ip,iport.port);
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