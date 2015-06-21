//
// Created by pablo on 07/06/15.
//

#ifndef HARFS_CLIENT_JSONWRITER_H
#define HARFS_CLIENT_JSONWRITER_H

#include <string>
#include "../../../libs/rapidjson/stringbuffer.h"
#include "../../../libs/rapidjson/writer.h"

using namespace std;
using namespace rapidjson;

class JsonWriter {
public:
    static string confirmationLogin(const char*,bool cheack);
    static string confirmationUpdate(const char*,bool cheack);
    static string confirmation(const char*,bool cheack);
    static string listStorage(const char*, void* list,const int len);
    static string updateStorage(const char*, void* list,const int len);
    static string sendStructure(const char*, void* list,const int len);
    static string confirmationCreationStorage(const char*,bool cheack);
};


#endif //HARFS_CLIENT_JSONWRITER_H
