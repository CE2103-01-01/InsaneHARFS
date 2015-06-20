//
// Created by pablo on 07/06/15.
//


#include "command-line.h"


CLI* CLI::singleton = NULL;
// cout <<  << endl;
CLI::CLI() {
    existeStorage = false;
    defineRegister=false;
    signIn=false;
    cout << WELCOME << endl;
    while(!signIn){
        logIn();
    }

}

void CLI::logIn() {
    std::cout<<"Please log in"<<std::endl;
    string user;
    string password;
    cout<<"Plase input the user name"<<endl;
    getline(cin,user);
    cout<<"Please input the password"<<endl;
    getline(cin,password);
    JsonWriter::logIn(user.c_str(),password.c_str());



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
    else if(num==5)saveRegister();
    else if(num==6)deleteRegister();
    else if(num==7)getRegister();
    else if(num==8) createUser();
    else if(num==9)setPermission();
    else if(num==10)testPermission();
    else if(num==11){
             std::cout<<"Thanks for using"<<endl;
             signIn=false;
             logIn();
         }
    else(cycleOptions());
}

void CLI::defineSchema() {
    if (existeStorage) {
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
        defineRegister = true;

    }
    else{
        std::cout<<"Currently no Storage to define the schema"<<std::endl;
    }
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
    existeStorage=true;
    JsonWriter::createStorageBlock(input_name,input_organization,"1");

}
void CLI::listStorageBlock() {
    JsonWriter::listStorageBlock();
}

void CLI::deleteStorageBlock() {
    string input;
    cout<< "Please insert the UID of the storage block which you want to delete"<<endl;
    getline(cin,input);
    string json =string(JsonWriter::deleteStorageBlock(input.c_str()));
    cycleOptions();
}
void CLI::saveRegister() {

}

void CLI::getRegister(){
    string input;
    cout<<"Please insert the number of colum where you want to get the register"<<endl;
    getline(cin,input);
    string key;
    cout<<"Please insert the search key of your register"<<endl;
    getline(cin,key);
    string json = string(JsonWriter::getRegister(input.c_str(),key.c_str()));
    TCPClient::getInstance()->send(json.c_str(),json.length()+1);
    cycleOptions();
}

CLI::~CLI() {
    free(columns);
}

void CLI::deleteRegister() {

}



void CLI::createUser() {
    string user;
    cout<<"Please insert the user name"<<endl;
    getline(cin,user);
    string password;
    cout<<"Please insert the password"<<endl;
    getline(cin,password);
    string json = string(JsonWriter::createUser(user.c_str(),password.c_str()));
    TCPClient::getInstance()->send(json.c_str(),json.length()+1);
    cycleOptions();
}

void CLI::setPermission() {
    string user;
    string uid;
    cout<< "Please insert the user name which you want to associate: "<<endl;
    getline(cin,user);
    cout<<"Please insert the uid of the storage which you want to associate: "<<endl;
    getline(cin,uid);
    string json = string(JsonWriter::setPermission(user.c_str(),uid.c_str()));
    TCPClient::getInstance()->send(json.c_str(),json.length()+1);
    cycleOptions();

}

void CLI::testPermission() {
    string user;
    string uid;
    cout<< "Please insert the user name which you want to associate: "<<endl;
    getline(cin,user);
    cout<<"Please insert the uid of the storage which you want to associate: "<<endl;
    getline(cin,uid);
    string json = string(JsonWriter::setPermission(user.c_str(),uid.c_str()));
    TCPClient::getInstance()->send(json.c_str(),json.length()+1);
    cycleOptions();
}

CLI* CLI::getInstance() {
    if(singleton==NULL){
        singleton = new CLI();
    }
    return singleton;
}

void CLI::messageHandler(string message) {
    rapidjson::Document document;
    document.Parse(message.c_str());

}
