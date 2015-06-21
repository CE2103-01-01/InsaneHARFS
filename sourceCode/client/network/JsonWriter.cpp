//
// Created by pablo on 07/06/15.
//

#include <iostream>
#include "JsonWriter.h"

const char *JsonWriter::createSchema(bool check) {

    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("op");writer.String("createSchemaConf");
    writer.String("conf");writer.Bool(check);

    writer.EndObject();
    return s.GetString();
}
const char* JsonWriter::createStorageBlock(bool check, unsigned int uid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op");writer.String("createBlockConf");
    writer.String("");

    writer.EndObject();
    return s.GetString();
}
const char* JsonWriter::listStorageBlock() {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op"); writer.String("list");
    writer.EndObject();
    return s.GetString();
}

const char* JsonWriter::deleteStorageBlock(const char* uid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op");writer.String("deleteStorageBlock");
    writer.String("uid");writer.String(uid);
    writer.EndObject();
    return s.GetString();
}

const char* JsonWriter::getRegister(const char* colum,const char* key) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op"); writer.String("getData");
    writer.String("colum");writer.String(colum);
    writer.String("key");writer.String(key);
    writer.EndObject();
    return s.GetString();

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

const char* JsonWriter::logIn(const char *user, const char *password) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op"); writer.String("logIn");
    writer.String("user");writer.String(user);
    writer.String("password");writer.String(password);
    writer.EndObject();
    return s.GetString();
}

const char* JsonWriter::setPermission(const char* user, const char * uid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op"); writer.String("setPermission");
    writer.String("user");writer.String(user);
    writer.String("uid");writer.String(uid);
    writer.EndObject();
    return s.GetString();
}
const char* JsonWriter::testPermission(const char * user, const char * uid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.String("op"); writer.String("testPermission");
    writer.String("user");writer.String(user);
    writer.String("uid");writer.String(uid);
    writer.EndObject();
    return s.GetString();
}

