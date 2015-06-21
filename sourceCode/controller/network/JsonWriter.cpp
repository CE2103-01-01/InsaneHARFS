//
// Created by pablo on 20/06/15.
//

#include "JsonWriter.h"

string JsonWriter::setStatus(bool status) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("op");writer.String("status");
    writer.String("data");writer.Bool(status);

    writer.EndObject();
    return (char *) s.GetString();
}
