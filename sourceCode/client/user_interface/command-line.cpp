//
// Created by pablo on 07/06/15.
//


#include "command-line.h"
#include "../network/JsonWriter.h"

// cout <<  << endl;
CLI::CLI() {
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
}

CLI::~CLI() {
    free(columns);
}
