//
// Created by pablo on 03/06/15.
//

#include <iostream>
#include "FileManager.h"

FileManager::FileManager() {
}
/**
 * Search if a file exists
 */
bool FileManager::checkFileExistence(const string& path)
{
    ifstream f(path.c_str());
    bool open = f.is_open();
    f.close();
    return open; //TODO-close file
}

FileManager::~FileManager() {

}
/**
 * writes char* on a file
 * Exit codes:
 * 0: write successful
 * 1: file created
 * -1: file couldnt create
 */
int FileManager::write(const string &path, const int & offset, char *data) {
    fstream iofile;
    const bool exists = checkFileExistence(path);
    if (!exists) {
        cerr << "File " << path << " not found." << endl;

        iofile.open(path.c_str());
        if (!iofile.is_open()) {
            cerr << "Could not create file." << endl;
            return -1;
        }
        cout << "File created." << endl;
    }
    else iofile.open(path.c_str());

    iofile.seekg(offset);
    iofile << *data;
    iofile.close();
    if (exists) return 0;
    else return 1;
}

char *FileManager::read(const string &path, const int & offset, const int& size) {
    fstream iofile;
    const bool exists = checkFileExistence(path);
    if (!exists) {
        cerr<< "File doesnt exists"<< endl;
        return nullptr;
    }
    iofile.open(path.c_str());


}
