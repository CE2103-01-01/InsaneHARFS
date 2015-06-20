//
// Created by pablo on 05/06/15.
//

#include "TCPServer.h"


TCPServer::TCPServer() {
    off = false;
    try {
        TCPServerSocket servSock(Configuration::getInstance()->getPort());     // Server Socket object

        while(!off) {   // Run forever
            HandleTCPClient(servSock.accept());       // Wait for a client to connect
        }
    } catch (SocketException &e) {
        cerr << e.what() << endl;
        abort();
    }
}

TCPServer::~TCPServer() {
    off = true;
}

void TCPServer::HandleTCPClient(TCPSocket *sock) {
    cout << "Handling client ";
    try {
        cout << sock->getForeignAddress() << ":";
    } catch (SocketException e) {
        cerr << "Unable to get foreign address" << endl;
    }
    try {
        cout << sock->getForeignPort();
    } catch (SocketException e) {
        cerr << "Unable to get foreign port" << endl;
    }
    cout << endl;

    receive(sock);


}

void TCPServer::receive(TCPSocket *sock) {
    while(!off)
    try {
        // Send received string and receive again until the end of transmission
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
        //if(message.length()==0)

        if (sock->send(message.c_str(),message.length()+1)==0)
        {
            sock->~Socket(); //Closed Socket
            std::cout << "Disconnected" << std::endl;
            break;
        }
        std::cout << "Message Received: " << message<<std::endl;

    } catch(SocketException &e) {
        cerr << e.what() << endl;
        exit(1);
    }
}
