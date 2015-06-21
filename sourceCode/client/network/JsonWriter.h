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
    static string createSchema(const char*,int*,int);
    static string createStorageBlock(const char*,const char*,const char*,const char*);
    static string listStorageBlock(const char*);
    static string deleteStorageBlock(const char*,const char*);
    static string getRegister(const char*,const char*,const char*);
    static string createUser(const char* ,const char* , const char* );
    static string logIn(const char* user, const char* password);
    static string setPermission(const char*,const char*,const char*);
    static string testPermission(const char*,const char*,const char*);
    static string updateStorage(const char*);
    static string getStructure(const char*,const char*);
    static string createRegister(const char*,const char*);


};


#endif //HARFS_CLIENT_JSONWRITER_H
