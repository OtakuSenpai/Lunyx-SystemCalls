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

Lunyx::FilePath::FilePath(const std::string& path) {
    absolute_path = path;
    slash_count = num_of_slashes(path);

    std::string temp, tempFile = path,file;
    size_t count = slash_count;

    bool first = true;

    do {
        std::cout << "\nCount: " << count << std::endl;
        if(count > 0) {
            file = tempFile.substr(0, tempFile.find('/'));
            temp = tempFile.substr(tempFile.find('/') + 1, tempFile.length());
            tempFile = temp;

            if(pathname == "/" || first) {
                first = false;
                continue;
            }
            else if(!first)
                pathname = pathname + '/' + file;

            if(temp.find('/') == std::string::npos)
                break;

            std::cout << "Path: " << pathname << std::endl;
            std::cout << "Temp: " << temp << std::endl;
            std::cout << "TempFile: " << tempFile << std::endl;

            --count;
        }
    } while(count != 1);

    filename = temp.substr(temp.find('/') + 1,temp.size());
}


void Lunyx::FilePath::cd_path() {

    std::string temp1, temp2, tmpPath = pathname;

    while(auto v = (pathname.find('/') != std::string::npos)) {
        temp1 = tmpPath.substr(0, v);
        temp2 = temp1;
        temp1 = temp2.substr(v + 1, temp2.length());
        std::cout << "temp is: " << temp1 << std::endl;
    }
}