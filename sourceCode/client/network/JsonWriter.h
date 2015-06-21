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
    static const char * createSchema(const char*,int*,int);
    static const char* createStorageBlock(const char*,const char*,const char*,const char*);
    static const char* listStorageBlock(const char*);
    static const char* deleteStorageBlock(const char*,const char*);
    static const char* getRegister(const char*,const char*,const char*);
    static const char* createUser(const char* ,const char* , const char* );
    static const char* logIn(const char* user, const char* password);
    static const char* setPermission(const char*,const char*,const char*);
    static const char* testPermission(const char*,const char*,const char*);
    static const char* updateStorage(const char*);


};


#endif //HARFS_CLIENT_JSONWRITER_H
