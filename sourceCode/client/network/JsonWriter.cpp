//
// Created by pablo on 07/06/15.
//

#include <iostream>
#include "JsonWriter.h"

const char *JsonWriter::createSchema(int *pInt, int size) {

    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op"); writer.String("define");
    writer.String("columns");
    writer.StartArray();
    for (int i = 0; i < size; ++i) {
        writer.Int(pInt[i]);
    }
    writer.EndArray();
    writer.EndObject();
    return s.GetString();
}
string JsonWriter::createStorageBlock(string name,string structure, string raid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op");writer.String("createBlock");
    writer.String("name");writer.String(name.c_str());
    writer.String("structure");writer.String(structure.c_str());
    writer.String("raid");writer.String(raid.c_str());
    writer.EndObject();
    std::cout<<s.GetString()<<std::endl;
}
string JsonWriter::listStorageBlock() {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op"); writer.String("list");
    writer.EndObject();
}

void JsonWriter::deleteStorageBlock(string uid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op");writer.String("deleteStorageBlock");
    writer.String("uid");writer.String(uid.c_str());
    writer.EndObject();
}

string JsonWriter::getRegister(string offset) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op"); writer.String("getData");

}

const char *JsonWriter::createUser(const char* user, const char* password) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op"); writer.String("createUser");
    writer.String("user");writer.String(user);
    writer.String("password");writer.String(password);
    writer.EndObject();
    return s.GetString();
}
