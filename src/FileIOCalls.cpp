//
// Created by neel on 3/14/19.
//

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "FileIOCalls.hpp"

using namespace Lunyx;

FileIOCalls::FileIOCalls(const std::string& file) {
    filename = file;
    int count = num_of_slashes(file);
    std::string temp, tempFile = file;
    for(auto v = tempFile[0]; v != '\0'; v++) {
        if(count > 0) {
            temp = tempFile.substr(0,tempFile.find(v));
            tempFile = tempFile.substr(tempFile.find(v) + 1, tempFile.length());
                    --count;
            open(temp.c_str(),O_CREAT | O_DIRECTORY);
        }
        else {
            file_desc = open(temp.c_str(), O_CREAT | O_RDWR);
        }
    }
}

void FileIOCalls::write_data() {
    std::string input;

    do {
        std::cin >> input;
        const void* buf = input.c_str();
        size_t size = (size_t) input.length();
        int ret = write(file_desc,buf,size);
        if(ret == -1)
            throw std::runtime_error("Error in FileIOCall.cpp : Failed to write to file!!!");
        else
            std::cout << "\nNumber of bytes written: " << ret << std::endl;
    } while(input[input.size() - 1] != '\n');
}

std::string& FileIOCalls::read_data() {
    std::string input;
    void* buffer;

    do {
        std::cin >> input;

        int ret = read(file_desc,buffer,1000);
        if(ret > 0) {
            input = std::string(const_cast<const char*>(reinterpret_cast<char*>(buffer)));
            std::cout << "\nNuber of bytes read: " << ret << std::endl;
        }
        else if(ret == 0)
            std::cout << "EOF detected!!!" << std::endl;
        else
            throw std::runtime_error("Error in FileIOCall.cpp : Failed to read from file!!!");
    } while(input[input.size() - 1] != '\n');

    return input;
}

FileIOCalls::~FileIOCalls() {
    int ret = close(file_desc);
    if(ret == -1)
        throw std::runtime_error("Error in FileIOCalls : Couldn't close the file!!!");
}