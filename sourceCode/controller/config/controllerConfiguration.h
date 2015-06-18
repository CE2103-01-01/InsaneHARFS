#ifndef CONFIGURATION_INSANEHARFS
#define CONFIGURATION_INSANEHARFS

#include <stddef.h>
#include <stdint.h>
#include "../../../libs/rapidjson/document.h"
#include "../../../libs/rapidjson/reader.h"
#include "../network/ipPort.h"
#include <fstream>
#include <iostream>
#include <vector>

#define SHARED_SECRET_LENGTH 64




using namespace rapidjson;
using namespace std;
class Configuration {
private:
    static Configuration *ConfigurationSingleton;

    Configuration(string cfgPath);
    char sharedSecret[SHARED_SECRET_LENGTH];
    unsigned short port;
    unsigned short numberOfDisks;
    ipPort* diskNodes;


public:
    ~Configuration();
    static Configuration *getInstance();
    static Configuration *initializeAndGetInstance(string cfgPath);
    const char *getSharedSecret() const;
    unsigned short getPort() const ;
    unsigned short getNumberOfDiks() const;
    ipPort *getDiskNodes() const;

};


#endif //CONFIGURATION_INSANEHARFS
