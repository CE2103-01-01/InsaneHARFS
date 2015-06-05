#include <fstream>
#include <iostream>
#include "Configuration.h"

Configuration *Configuration::ConfigurationSingleton = nullptr;

Configuration::Configuration(string cfgPath) {
    string file;
    string line;
    ifstream myfile (cfgPath);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            file.append(line);
        }
        myfile.close();
    }
    else
    {
        cerr<< "Couldnt open: "<<cfgPath<<endl;
        return ;
    }
    Document document;
    if (document.Parse(file.c_str()).HasParseError()) {
        cerr << "Couldnt Parse" << endl;
        return ;
    }
    string sharedSecretStr = document.FindMember("sharedSecret")->value.GetString();
    for (int i = 0; i < SHARED_SECRET_LENGTH; ++i) {
        sharedSecret[i] = sharedSecretStr[i];
    }
    diskSize = document.FindMember("diskSize")->value.GetUint();
    port = document.FindMember("port")->value.GetUint();
    path = (document.FindMember("path")->value.GetString());

}




Configuration *Configuration::getInstance() {
    if (!ConfigurationSingleton) return nullptr;
    return ConfigurationSingleton;
}

Configuration *Configuration::initializeAndGetInstance(string cfgPath) {
    if (!ConfigurationSingleton) ConfigurationSingleton = new Configuration(cfgPath);
    else{
        delete ConfigurationSingleton;
        ConfigurationSingleton = new Configuration(cfgPath);
    }
    return ConfigurationSingleton;
}
//Getters
const char *Configuration::getSharedSecret() const {
    return sharedSecret;
}

size_t Configuration::getDiskSize() const {
    return diskSize;
}

uint16_t Configuration::getPort() const {
    return port;
}

string Configuration::getPath() const {
    return path;
}


