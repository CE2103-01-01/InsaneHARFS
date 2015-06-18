//
// Created by pablo on 18/06/15.
//

#ifndef HARFS_CLIENT_IPPORT_H
#define HARFS_CLIENT_IPPORT_H
#define IP_LENGTH 16
#include <string>
using namespace std;
class ipPort {
public:
    ipPort(string ip, unsigned short port);
    char ip[IP_LENGTH];
    unsigned short port;
};


#endif //HARFS_CLIENT_IPPORT_H
