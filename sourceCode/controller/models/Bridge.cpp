//
// Created by pablo on 20/06/15.
//

#include "Bridge.h"
#include "../../../libs/rapidjson/document.h"


Bridge * Bridge::singleton = NULL;

void Bridge::initialize(DoubleLinkedList<TCPSocket> *pSockets){
    if (!singleton) singleton = new Bridge(pSockets);
}

Bridge *Bridge::getInstance() {
    return singleton;
}

Bridge::Bridge(DoubleLinkedList<TCPSocket> *pSockets) :sockets(pSockets) {
    clients = new DoubleLinkedList<SockUser>();
    string json = JsonWriter::setStatus(true);
    sockets->getHead()->getData()->send(json.c_str(),json.length()+1);
}

void Bridge::sendToDisks(string message, TCPSocket *sock) {
    DoubleLinkedNode<TCPSocket> *socketNode = sockets->getHead();
    while (!socketNode)
    {
        socketNode->getData()->send(message.c_str(),message.length());
        socketNode = socketNode->getNext();
    }
    rapidjson::Document document;
    document.Parse(message.c_str());
    SockUser client = SockUser(sock, document.FindMember("user")->value.GetString());
    clients->insertNewTail(client);
}

void Bridge::sendToUser(string message) {

}
