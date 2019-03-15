//
// Created by neel on 3/14/19.
//

#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>

#include "FileIOCalls.hpp"
#include "helpers.hpp"

using namespace Lunyx;

FileIOCalls::FileIOCalls(const std::string& file) {
    filename = file;
    int count = Lunyx::num_of_slashes(file);
    std::cout << "Count: " << count << std::endl;
    std::string temp, tempFile = file,path;

    do {
        std::cout << "\nCount: " << count << std::endl;
        if(count > 0) {
            path = tempFile.substr(0, tempFile.find('/'));
            temp = tempFile.substr(tempFile.find('/') + 1, tempFile.length());
            tempFile = temp;
            std::cout << "Path: " << path << std::endl;
            std::cout << "Temp: " << temp << std::endl;
            std::cout << "TempFile: " << tempFile << std::endl;
            chdir(path.c_str());
            --count;
        }
    } while(count != 0);

    if(count == 0) {
        std::cout << "Path: " << path << std::endl;
        chdir(path.c_str());
        temp = temp.substr(temp.find('/') + 1, temp.length());
        file_desc = open(temp.c_str(), O_CREAT | O_RDWR);
    }

    if(file_desc == -1)
        throw std::runtime_error("Error in FileIOCalls : Unable to open file!!");
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
            std::cout << "\nNumber of bytes read: " << ret << std::endl;
        }
        else if(ret == 0)
            std::cout << "EOF detected!!!" << std::endl;
        else
            throw std::runtime_error("Error in FileIOCall.cpp : Failed to read from file!!!");
    } while(input[input.size() - 1] != '\n');

    return input;
}

std::string& FileIOCalls::read_data(size_t count) {
    std::string input;
    void* buffer;

    do {
        std::cin >> input;

        int ret = read(file_desc,buffer,count);
        if(ret > 0) {
            input = std::string(const_cast<const char*>(reinterpret_cast<char*>(buffer)));
            std::cout << "\nNumber of bytes read: " << ret << std::endl;
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
    if(ret > -1) std::cout << "Closed file." << std::endl;
    else if(ret == -1)
        throw std::runtime_error("Error in FileIOCalls : Couldn't close the file!!!");
}