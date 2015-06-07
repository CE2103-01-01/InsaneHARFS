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
using namespace std;
class TCPClient {
private:
    TCPSocket *sock;
public:
    TCPClient();
};


#endif //HARFS_CLIENT_TCPCLIENT_H
