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
    static const char* confirmationLogin(const char*,bool cheack);
    static const char* confirmationUpdate(const char*,bool cheack);
    static const char* confirmation(const char*,bool cheack);
    static const char* listStorage(const char*,const void* list,const int len);
    static const char* updateStorage(const char*,const void* list,const int len);
    static const char* sendStructure(const char*,const void* list,const int len);
    static const char* confirmationCreationStorage(const char*,bool cheack);
};


#endif //HARFS_CLIENT_JSONWRITER_H
