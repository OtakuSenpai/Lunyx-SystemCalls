//
// Created by neel on 3/15/19.
//

#include <iostream>
#include <string>
#include <unistd.h>
#include <errno.h>

#include "helpers.hpp"

int Lunyx::FilePath::num_of_slashes(const std::string& file) {
    int count = 0;
    for(auto c : file)
        if(c == '/') ++count;

    return count;
}

Lunyx::FilePath::FilePath(const std::string& path) {
    absolute_path = path;
    slash_count = num_of_slashes(path);

    std::string temp, tempFile = path,file;
    size_t count = slash_count;

    bool first = true;

    do {
        if(count > 0) {
            file = tempFile.substr(0, tempFile.find('/'));
            temp = tempFile.substr(tempFile.find('/') + 1, tempFile.length());
            tempFile = temp;

            if(relative_path == "/" || first) {
                first = false;
                continue;
            }
            else if(!first)
                relative_path = relative_path + '/' + file;

            if(temp.find('/') == std::string::npos)
                break;

            --count;
        }
    } while(count != 1);

    if(Lunyx::has_it(temp,'/')) {
        filename = temp.substr(temp.find('/') + 1,temp.size());
    }
    else
        filename = temp;
}


void Lunyx::FilePath::cd_path() {
    std::string temp1, temp2, tmpPath = relative_path;
    std::string cdpath;

    size_t count = slash_count - 1;
    bool first = true;

    std::cout << "Relative Path: " << tmpPath << std::endl;

    do {
        if(count > 0) {
            temp1 = tmpPath.substr(0, tmpPath.find('/'));
            temp2 = tmpPath.substr(tmpPath.find('/') + 1, tmpPath.length());
            tmpPath = temp2;

            if(tmpPath == "/" || first) {
                first = false;
                continue;
            }
            else if(!first){
                cdpath = cdpath + '/' + temp1;
                std::cout << "Moving to: " << cdpath << std::endl;
                chdir(cdpath.c_str());
                cdpath.clear();
            }

            if(tmpPath.find('/') == std::string::npos)
                break;

            --count;
        }
    } while(count != 1);

    temp2 = tmpPath.substr(tmpPath.find('/') + 1, tmpPath.length()) + '/';
    chdir(temp2.c_str());
}

std::string Lunyx::find_errno(const int& error_code) {
    std::string retValue;

    switch(error_code) {
        case EPERM :
            retValue = "Operation not permitted.";
            break;
        case EIO :
            retValue = "Input/output error.";
            break;
        case ENXIO :
            retValue = "No such device or address.";
            break;
        case EACCES :
            retValue = "Permission denied.";
            break;
        case EBUSY :
            retValue = "Device or resource busy.";
            break;
        case ENODEV :
            retValue = "No such device.";
            break;
        case EISDIR :
            retValue = "Is a directory.";
            break;
        case ENOTTY :
            retValue = "Inappropriate ioctl for device.";
            break;
        case ETXTBSY :
            retValue = "Text file busy.";
            break;
        case ENOSPC :
            retValue = "No space left on device.";
            break;
        case EROFS :
            retValue = "Read-only file system.";
            break;
        default:
            retValue = "Unknown error.";
    }
    return retValue;
}

bool Lunyx::has_it(const std::string &str, char match) {
    bool found = false;

    for(auto i = str.begin(); i != str.end(); i++)
        if(*i == match)
            found = true;

    return found;
}