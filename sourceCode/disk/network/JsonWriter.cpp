//
// Created by pablo on 07/06/15.
//

#include <iostream>
#include "JsonWriter.h"

string JsonWriter::confirmationLogin(const char* user,bool cheack){
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("login");
    writer.String("bool");writer.Bool(cheack);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::listStorage(const char* user,void *list,const int len) {
    char* pointer = static_cast<char*>(list) + '\0';
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("listStorage");
    writer.String("data"); writer.String(pointer);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::updateStorage(const char* user, void *list, const int len) {
    char* pointer = static_cast<char*>(list) + '\0';
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("updateStorage");
    writer.String("infoStorage"); writer.String(pointer);
    writer.String("size");writer.Int(len);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::sendStructure(const char* user, void *list, const int len) {
    char* pointer = static_cast<char*>(list) + '\0';
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("updateStructure");
    writer.String("infoStrcture"); writer.String(pointer);
    writer.String("size");writer.Int(len);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::confirmationUpdate(const char* user,bool cheack) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op"); writer.String("update");
    writer.String("bool");writer.Bool(cheack);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::confirmation(const char * user, bool cheack) {
    StringBuffer s ;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op");writer.String("confirm");
    writer.String("bool");writer.Bool(cheack);
    writer.EndObject();
    return s.GetString();
}

string JsonWriter::confirmationCreationStorage(const char * user, bool cheack) {
    StringBuffer s ;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("user"); writer.String(user);
    writer.String("op");writer.String("storageConfirmation");
    writer.String("bool");writer.Bool(cheack);
    writer.EndObject();
    return s.GetString();
}