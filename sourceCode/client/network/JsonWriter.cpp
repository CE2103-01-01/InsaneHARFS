//
// Created by pablo on 07/06/15.
//

#include <iostream>
#include "JsonWriter.h"

string JsonWriter::createSchema(const char* user,int *pInt, int size) {

    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
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
string JsonWriter::createStorageBlock(const char* user,const char* name,const char* structure, const char* raid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op");writer.String("createBlock");
    writer.String("name");writer.String(name);
    writer.String("structure");writer.String(structure);
    writer.String("raid");writer.String(raid);
    writer.EndObject();
    return s.GetString();
}
string JsonWriter::listStorageBlock(const char* user) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("list");
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::deleteStorageBlock(const char* user,const char* uid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op");writer.String("deleteStorageBlock");
    writer.String("uid");writer.String(uid);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::getRegister(const char* user,const char* colum,const char* key) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("getData");
    writer.String("colum");writer.String(colum);
    writer.String("key");writer.String(key);
    writer.EndObject();
    return s.GetString();

}

string JsonWriter::createUser(const char* user,const char* userToCreate, const char* password) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("createUser");
    writer.String("user");writer.String(userToCreate);
    writer.String("password");writer.String(password);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::logIn(const char *user, const char *password) {
    cout<<user<<password<<endl;
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("op"); writer.String("logIn");
    writer.String("user");writer.String(user);
    writer.String("password");writer.String(password);
    writer.EndObject();

    return s.GetString();
}

string JsonWriter::setPermission(const char* user,const char* userToSet, const char * uid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("setPermission");
    writer.String("user");writer.String(userToSet);
    writer.String("uid");writer.String(uid);
    writer.EndObject();
    return s.GetString();
}
string JsonWriter::testPermission(const char* user,const char * userToTest, const char * uid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("testPermission");
    writer.String("user");writer.String(userToTest);
    writer.String("uid");writer.String(uid);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::updateStorage(const char * user) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user");writer.String(user);
    writer.String("op");writer.String("updateStorage");
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::getStructure(const char * user, const char * file) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user");writer.String(user);
    writer.String("op");writer.String("getStructure");
    writer.String("fileName");writer.String(file);
    writer.EndObject();
    return s.GetString();

}
string JsonWriter::createRegister(const char *user, const char *file) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user");writer.String(user);
    writer.String("op");writer.String("createRegister");
    writer.String("data");writer.String(file);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::deleteRegister(const char *user, const char *file) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user");writer.String(user);
    writer.String("op");writer.String("deleteRegister");
    writer.String("data");writer.String(file);
    writer.EndObject();
    return s.GetString();
}
