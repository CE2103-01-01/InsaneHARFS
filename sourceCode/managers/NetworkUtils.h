//
// Created by pablo on 05/06/15.
//

#ifndef HARFS_DISK_NETWORKUTILS_H
#define HARFS_DISK_NETWORKUTILS_H

#include "../../libs/practicalsocket/PracticalSocket.h"  // For Socket and SocketException
#include <iostream>           // For cerr and cout
#include <cstdlib>            // For atoi()

#define  RCVBUFSIZE 32    // Size of receive buffer

class NetworkUtils {
private:
    void HandleTCPClient(TCPSocket *sock);
    int off;
public:
    NetworkUtils();
    ~NetworkUtils();
};


#endif //HARFS_DISK_NETWORKUTILS_H
