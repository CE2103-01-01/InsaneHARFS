//
// Created by pablo on 18/06/15.
//


#include <iostream>
#include "ipPort.h"

ipPort::ipPort(string ipNode, unsigned short port) : port(port) {
    for (int i = 0; i < IP_LENGTH; ++i) {
        ip[i] = ipNode[i];
        if(ipNode[i]==0) break;
    }

}