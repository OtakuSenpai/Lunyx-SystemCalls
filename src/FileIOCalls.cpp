//
// Created by neel on 3/14/19.
//

#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "FileIOCalls.hpp"
#include "helpers.hpp"

using namespace Lunyx;

FileIOCalls::FileIOCalls(const std::string& file) : fp(file) {

    file_desc = open(fp.absolute_path.c_str(),O_RDWR);

    if(file_desc == -1)
        throw std::runtime_error("Error in FileIOCalls : Unable to open file!!\nError is: " + Lunyx::find_errno(errno));
}

size_t FileIOCalls::write_data(const std::string& input) {
    file_desc = open(filename.c_str(),O_WRONLY);

    if(file_desc == -1)
        throw std::runtime_error("Error in FileIOCalls : Unable to open file!!\nError is: " + Lunyx::find_errno(errno));

    const void* buf = input.c_str();
    ssize_t size = (ssize_t) input.length();
    ssize_t ret = write(file_desc,buf,size);
    std::cout << "ret is:" << ret << std::endl;
    if(ret == -1)
        throw std::runtime_error("Error in FileIOCall.cpp : Failed to write to file!!!\nError is: " + Lunyx::find_errno(errno));
    else if(ret != size) {
        std::cout << "Ret is not equal to size: " << ret << std::endl;
        std::string temp = input.substr(ret + 1,input.size());
        const void* bufTmp = temp.c_str();
        ssize_t s = (ssize_t) temp.length();
        ssize_t tmpRet = write(file_desc,bufTmp,s);
        if(tmpRet == -1)
            throw std::runtime_error("Error in FileIOCall.cpp : Failed to write to file!!!");
        ret = ret + tmpRet;
    }
    else if(ret == 0)
        throw std::runtime_error("Error in FileIOCall.cpp : Failed to write to file!!!\nError is: " + Lunyx::find_errno(errno));

    return ret;
}

std::string FileIOCalls::read_data() {
    void* buffer;
    char input;
    std::string retValue;

    do {
        int ret = read(file_desc,buffer,1);
        if(ret > 0) { // Successful Read
            input = *reinterpret_cast<char*>(buffer);
            std::cout << "\nNumber of bytes read: " << ret << std::endl;
            retValue = retValue + input;
        }
        else if(ret == 0) // EOF
            std::cout << "EOF detected!!!" << std::endl;
        else
            throw std::runtime_error("Error in FileIOCall.cpp : Failed to read from file!!!\nError is: " + Lunyx::find_errno(errno));
    } while(input != '\n');

    return retValue;
}

std::string FileIOCalls::read_data(size_t count) {
    void* buffer;
    char input;
    std::string retValue;

    do {
        int ret = read(file_desc,buffer,1);
        if(ret > 0) { // Successful Read
            input = *reinterpret_cast<char*>(buffer);
            std::cout << "\nNumber of bytes read: " << ret << std::endl;
            retValue = retValue + input;
        }
        else if(ret == 0) // EOF
            std::cout << "EOF detected!!!" << std::endl;
        else
            throw std::runtime_error("Error in FileIOCall.cpp : Failed to read from file!!!\nError is: " + Lunyx::find_errno(errno));
    } while(input != '\n');

    return retValue;
}

void Lunyx::FileIOCalls::cd_path() {
    fp.cd_path();
}

FileIOCalls::~FileIOCalls() {
    close(file_desc);
}