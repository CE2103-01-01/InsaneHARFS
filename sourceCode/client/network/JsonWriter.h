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
    static const char * createSchema(int*,int);
    static string createStorageBlock(string,string,string);
    static string listStorageBlock();
    static void deleteStorageBlock(string);
    static string getRegister(string);

};


#endif //HARFS_CLIENT_JSONWRITER_H
