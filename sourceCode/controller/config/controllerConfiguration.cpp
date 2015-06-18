
#include "controllerConfiguration.h"

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
    port = document.FindMember("port")->value.GetUint();



    //DiskNodes
    const Value&diskNodesJSON = document.FindMember("diskNodes")->value; // Using a reference for consecutive access is handy and faster.
    diskNodes = static_cast<ipPort*>(malloc(sizeof(ipPort)*diskNodesJSON.Size()));
    for (SizeType i = 0; i < diskNodesJSON.Size(); i++)
    {
        string ipPortStr = diskNodesJSON[i].GetString();
        std::cout << ipPortStr << std::endl;
        //Split
        string delimiter = ":";
        int pos = ipPortStr.find(delimiter);
        string ip = ipPortStr.substr(0, pos);
        ipPortStr.erase(0, pos + delimiter.length());
        unsigned short port = atoi(ipPortStr.c_str());
        //save node
        *(diskNodes+i) = ipPort(ip,port);
    }

}




Configuration *Configuration::getInstance() {
    if (!ConfigurationSingleton) cerr<<"Uninitialized Configuration";
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

unsigned short Configuration::getPort() const {
    return port;
}



Configuration::~Configuration() {
}

unsigned short Configuration::getNumberOfDiks() const {
    return numberOfDisks;
}

ipPort *Configuration::getDiskNodes() const {
    return diskNodes;
}
