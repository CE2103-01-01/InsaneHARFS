//
// Created by roberto on 05/06/15.
//

#include "pathConstants.h"

namespace PathConstants{
    extern const std::string HOME_PATH = getenv("HOME");
    extern const std::string PROJECT_PATH = HOME_PATH+"/HARFS/";
    extern const std::string HARFS_EXT = ".harfs";
    extern const std::string HEADER_EXT = ".header";
    extern const std::string DATA_EXT = ".data";
    int a = mkdir(PROJECT_PATH.c_str(), 0777);
}