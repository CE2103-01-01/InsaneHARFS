//
// Created by pablo on 20/06/15.
//

#ifndef HARFS_CLIENT_BRIDGE_H
#define HARFS_CLIENT_BRIDGE_H


#include "../../dataStructures/DoubleLinkedList.h"
#include "../../../libs/practicalsocket/PracticalSocket.h"
#include "../network/JsonWriter.h"
class SockUser
{
public:
    SockUser(TCPSocket *socket, const string &user) : socket(socket), user(user) { }
    TCPSocket* socket;
    string user;
};
class Bridge {
public:
    static void initialize(DoubleLinkedList<TCPSocket> *sockets);
    static Bridge *getInstance();
    void sendToDisks(string message, TCPSocket *sock);
    void sendToUser(string message);
private:
    Bridge(DoubleLinkedList <TCPSocket> *sockets);
    static Bridge* singleton;
    DoubleLinkedList <TCPSocket> *sockets;
    DoubleLinkedList <SockUser> *clients;
};


#endif //HARFS_CLIENT_BRIDGE_H
