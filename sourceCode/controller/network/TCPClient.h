//
// Created by pablo on 06/06/15.
//

#ifndef HARFS_CONTROLLER_TCPCLIENT_H
#define HARFS_CONTROLLER_TCPCLIENT_H
#define  RCVBUFSIZE 32
#define SLEEP 100000
#include "../../../libs/practicalsocket/PracticalSocket.h"  // For Socket and SocketException
#include <iostream>           // For cerr and cout
#include <cstdlib>            // For atoi()
#include "../config/controllerConfiguration.h"


using namespace std;
class TCPClient {
private:
    TCPSocket *sock;
    bool on;
    void receive();
public:
    TCPClient(string ip, unsigned short &port);
    ~TCPClient();
};


#endif //HARFS_CLIENT_TCPCLIENT_H
