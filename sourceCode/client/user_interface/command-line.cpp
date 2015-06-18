//
// Created by pablo on 07/06/15.
//


#include "command-line.h"
#include "../network/JsonWriter.h"

// cout <<  << endl;
CLI::CLI() {
    existeRegister = false;
    cout << WELCOME << endl;
    defineSchema();
    cycleOptions();
}

void CLI::cycleOptions() {
    cout << OPTIONS << endl;
    string input;
    getline(cin, input);
}

void CLI::defineSchema() {
    string input;
    cout << COLUMNS_INSTRUCTS << std::endl;
    getline(cin, input);
    int columnNumber = atoi(input.c_str());
    columns = static_cast<int*>(malloc(sizeof(int)*columnNumber));
    for(int i = 0;i<columnNumber;i++) {
        cout << COLUMN << endl;
        getline(cin, input);
        columns[i] = atoi(input.c_str());
    }
    JsonWriter::createSchema(columns,columnNumber);
    existeRegister = true;
}
void CLI::createStorageBlock() {
    string input_name;
    cout<< Please_insert_the_name_of_the_storage_block<<endl;
    getline(cin,input_name);
    string input_organization;
    cout<< "Please insert the type of the organization"<<endl;
    cout<< "The organizations are:"
        << "1-AVL"
        << "2-Binary Tree"
        << "3-Binary Tree +"
        << "4-LinkedList"
        <<"Please insert the number of the organization:"<<endl;
    getline(cin,input_organization);
}
void CLI::listStorageBlock() {
}

void CLI::deleteStorageBlock() {
    string input;
    cout<< "Please insert the UID of the storage block which you want to delete"<<endl;
    getline(cin,input);
}
void CLI::saveRegiter() {
}


CLI::

CLI::~CLI() {
    free(columns);
}
