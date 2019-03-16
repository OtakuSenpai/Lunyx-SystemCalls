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

Lunyx::FilePath Lunyx::FilePath(const std::string& path) {
    absolute_path = path;
    slash_count = num_of_slashes(path);

    std::string temp, tempFile = path,file;
    size_t count = slash_count;

    do {
        std::cout << "\nCount: " << count << std::endl;
        if(count > 0) {
            file = tempFile.substr(0, tempFile.find('/'));
            pathname +=file;
            temp = tempFile.substr(tempFile.find('/') + 1, tempFile.length());
            tempFile = temp;
            pathname += temp;
            std::cout << "Path: " << pathname << std::endl;
            std::cout << "Temp: " << temp << std::endl;
            std::cout << "TempFile: " << tempFile << std::endl;
            --count;
        }
    } while(count != 0);

    if(count == 0) {
        std::cout << "Path: " << pathname << std::endl;
        std::cout << "File: " << file << std::endl;
        chdir(path.c_str());
        temp = temp.substr(temp.find('/') + 1, temp.length());
        filename = file;
        // file_desc = open(temp.c_str(), O_CREAT | O_RDWR, 0644);
    }
}
/*
void Lunyx::FilePath::cd_path(const std::string &path, const size_t& slash_count) {





}

*/