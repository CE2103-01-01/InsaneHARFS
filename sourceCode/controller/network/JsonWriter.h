//
// Created by pablo on 20/06/15.
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
    static char* setStatus(bool status);
};


#endif //HARFS_CLIENT_JSONWRITER_H
