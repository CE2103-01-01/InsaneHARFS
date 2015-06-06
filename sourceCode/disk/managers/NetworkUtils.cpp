//
// Created by pablo on 05/06/15.
//

#include "NetworkUtils.h"


NetworkUtils::NetworkUtils() {
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

NetworkUtils::~NetworkUtils() {
    off = true;
}

void NetworkUtils::HandleTCPClient(TCPSocket *sock) {
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

        // Send received string and receive again until the end of transmission
        char echoBuffer[RCVBUFSIZE];
        int recvMsgSize;
        while ((recvMsgSize = sock->recv(echoBuffer, RCVBUFSIZE)) > 0) { // Zero means
        // end of transmission
        // Echo message back to client
        sock->send(echoBuffer, recvMsgSize);
    }
    delete sock;
}
