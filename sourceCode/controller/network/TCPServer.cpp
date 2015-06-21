//
// Created by pablo on 05/06/15.
//

#include "TCPServer.h"


TCPServer::TCPServer() {
    clients = new DoubleLinkedList<TCPSocket>();
    off = false;
    try {
        serverSocket = new TCPServerSocket(Configuration::getInstance()->getPort());     // Server Socket object

        while(!off) {   // Run forever
            HandleTCPClient(serverSocket->accept());       // Wait for a client to connect
        }
    } catch (SocketException &e) {
        cerr << e.what() << endl;
        abort();
    }
}

TCPServer::~TCPServer() {
    off = true;
    serverSocket->cleanUp();
    delete clients;
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
    clients->insertNewTail(sock);
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
        if (message.length()==0) throw (SocketException("Empty Message", true));
        std::cout << "Message Received: " << message<<std::endl;

        Bridge::getInstance()->sendToDisks(message,sock);
    } catch(SocketException &e) {
        cerr<<e.what()<<endl;
        clients->deleteLink(sock);
        sock->~Socket(); //Closed Socket
        std::cout << "Disconnected" << std::endl;
        break;
    }
}

void TCPServer::sendAll(string message) {

}

DoubleLinkedList<TCPSocket> *TCPServer::getClients() {
    return clients;
}
