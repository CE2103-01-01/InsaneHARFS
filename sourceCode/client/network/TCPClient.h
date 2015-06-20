//
// Created by pablo on 06/06/15.
//

#ifndef HARFS_CLIENT_TCPCLIENT_H
#define HARFS_CLIENT_TCPCLIENT_H

#include "../../../libs/practicalsocket/PracticalSocket.h"  // For Socket and SocketException
#include <iostream>           // For cerr and cout
#include <cstdlib>            // For atoi()
#include "../config/clientConfiguration.h"
const int RCVBUFSIZE = 32;    // Size of receive buffer
#define SLEEP 100000
using namespace std;
class TCPClient {
private:
    TCPClient();
    static TCPClient *singleton;
    TCPSocket *sock;
    bool on;
public:
    static TCPClient *getInstance();
    void receive();
    void send(const void *buffer, int bufferLen);
    ~TCPClient();

    void initConnection();
};


#endif //HARFS_CLIENT_TCPCLIENT_H
