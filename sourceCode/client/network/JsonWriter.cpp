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
    std::cout << s.GetString() << std::endl;
    return s.GetString();
}
string JsonWriter::createStorageBlock(string name,int structure, int raid) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    writer.Srting("op");writer.String("createBlock");
    writer.String("name");writer.String(name);
    writer.Srting("structure");writer.String(sturcture);
    writer.String("raid");writer.String(raid);
    writer.EndObject();
    std::cout<<s.GetString()<<std::endl;

}
