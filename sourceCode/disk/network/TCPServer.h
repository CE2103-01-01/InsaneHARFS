//
// Created by pablo on 05/06/15.
//

#ifndef HARFS_DISK_NETWORKUTILS_H
#define HARFS_DISK_NETWORKUTILS_H

#include "../../../libs/practicalsocket/PracticalSocket.h"  // For Socket and SocketException
#include "../config/diskConfiguration.h"
#include <iostream>           // For cerr and cout
#include <cstdlib>            // For atoi()
#include "../../dataStructures/DoubleLinkedList.h"

#define  RCVBUFSIZE 32    // Size of receive buffer

class TCPServer {
private:
    void HandleTCPClient(TCPSocket *sock);
    int off;
    void receive(TCPSocket *sock);
    DoubleLinkedList<TCPSocket> clients;
public:
    TCPServer();
    ~TCPServer();
    void sendAll(string);
};


#endif //HARFS_DISK_NETWORKUTILS_H
