//
// Created by pablo on 07/06/15.
//


#include "command-line.h"


// cout <<  << endl;
CLI::CLI() {
    existeRegister = false;
    cout << WELCOME << endl;
    cycleOptions();
}

void CLI::cycleOptions() {
    std::cout << OPTIONS << std::endl;
    cout <<"Please choose an option: "<< endl;
    string input;
    getline(cin, input);
    int num = atoi(input.c_str());
         if(num==1) createStorageBlock();
    else if(num==2)listStorageBlock();
    else if(num==3) deleteStorageBlock();
    else if(num==4) defineSchema();
    else if(num==5) saveRegister();
    else if(num==6)deleteRegister();
    else if(num==7)search();
    else if(num==8)getRegister();
    else if(num==9) createUser();
    else if(num==10)setPermission();
    else if(num==11)testPermission();
    else(cycleOptions());
}

void CLI::defineSchema() {
        string input;
        cout << COLUMNS_INSTRUCTS << std::endl;
        getline(cin, input);
        int columnNumber = atoi(input.c_str());
        columns = static_cast<int *>(malloc(sizeof(int) * columnNumber));
        for (int i = 0; i < columnNumber; i++) {
            cout << COLUMN << endl;
            getline(cin, input);
            columns[i] = atoi(input.c_str());
        }
        JsonWriter::createSchema(columns, columnNumber);
        existeRegister = true;

    }

void CLI::createStorageBlock() {
    string input_name;
    cout<< "Please insert the name of the storage block"<<endl;
    getline(cin,input_name);
    string input_organization;
    cout<< "Please insert the type of the organization"<<endl;
    cout<< "The organizations are:"
        << "1-Binary Tree"
        << "2-LinkedList"
        <<"Please insert the number of the organization:"<<endl;
    getline(cin,input_organization);
    int num = atoi(input_organization.c_str());
    while(num!=1 or num!=2){
        cout<<"Information incorrect, please input the information again"<<std::endl;
        cout<<"Please insert the number of the organization:"<<endl;
        getline(cin,input_organization);
        num = atoi(input_organization.c_str());
    }
    JsonWriter::createStorageBlock(input_name,input_organization,"1");

}
void CLI::listStorageBlock() {
    JsonWriter::listStorageBlock();
}

void CLI::deleteStorageBlock() {
    string input;
    cout<< "Please insert the UID of the storage block which you want to delete"<<endl;
    getline(cin,input);
    JsonWriter::deleteStorageBlock(input);
}
void CLI::saveRegister() {
    if(existeRegister){

    }
}




CLI::~CLI() {
    free(columns);
}
