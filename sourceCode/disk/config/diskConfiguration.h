#ifndef CONFIGURATION_INSANEHARFS
#define CONFIGURATION_INSANEHARFS

#include <stddef.h>
#include <stdint.h>
#include "../../../libs/rapidjson/document.h"
#include "../../../libs/rapidjson/reader.h"

#define SHARED_SECRET_LENGTH 64

using namespace rapidjson;
using namespace std;
class Configuration {
private:
    static Configuration *ConfigurationSingleton;

    Configuration(string cfgPath);
    char sharedSecret[SHARED_SECRET_LENGTH];
    size_t diskSize;
    short port;
    string path;
public:
    ~Configuration();
    static Configuration *getInstance();
    static Configuration *initializeAndGetInstance(string cfgPath);
    const char *getSharedSecret() const;

    size_t getDiskSize() const ;

    unsigned short getPort() const ;

    string getPath() const ;
};


#endif //CONFIGURATION_INSANEHARFS
