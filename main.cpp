//
// Created by neel on 3/13/19.
//
#include <iostream>
#include <cstdlib>
#include <exception>

#include "ProcessCalls.hpp"
#include "FileIOCalls.hpp"
#include "helpers.hpp"

int main(int argc, char** argv) {

    /*
    Lunyx::ProcessCalls processCalls;
    int i = 0;

    std::cout << "argc is:" << argc << std::endl;
    if(argc != 1)
        do {
            std::cout << "argv[" << i << "] is: " << argv[i] << std::endl;
            ++i;
        } while(i < argc);


    if(argc == 1) {
        std::cout << "Options are: \n";
        std::cout << " -h -> Help section.\n"
                  << " -p -> Run the process calls.\n"
                  << " -f -> Run the file i/o calls. Here the options are 'w' and 'r'.\n"
                  << "       In case of -r, you can also specify count of char to read.\n"
                  << "       Example: lunyx -f -r 100. Default: 1000.\n";
    } else if(argc > 1) {
        if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
            std::cout << "Options are: \n";
            std::cout << " -h -> Help section.\n"
                      << " -p -> Run the process calls.\n"
                      << " -f -> Run the file i/o calls. Here the options are 'w' and 'r'.\n"
                      << "       In case of -r, you can also specify count of char to read.\n"
                      << "       Example: lunyx -f -r 100. Default: 1000.\n";
        }
        else if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'p') {
            processCalls = Lunyx::ProcessCalls();

            processCalls.process_a_call(argc,argv);
        }
        else if(argc == 3 && argv[1][0] == '-' && argv[1][1] == 'f' && argv[2][0] == '-' && argv[2][1] == 'w') {
            std::string file;
            std::cout << "Enter file path: ";
            std::cin >> file;
            std::cout << std::endl;
            Lunyx::FileIOCalls fileIoCalls = Lunyx::FileIOCalls(file);
            char* input;
            std::cout << "Enter data: ";
            std::cin >> input;
            std::cout << std::endl;
            std::cout << "Number of bytes written is: " << fileIoCalls.write_data(const_cast<const char*>(input)) << std::endl;
        }
        else if(argc == 3 && argv[1][0] == '-' && argv[1][1] == 'f' && argv[2][0] == '-' && argv[2][1] == 'r') {
            std::string file;
            std::cout << "Enter file path: ";
            std::cin >> file;
            std::cout << std::endl;
            Lunyx::FileIOCalls fileIoCalls = Lunyx::FileIOCalls(file);
            std::cout << fileIoCalls.read_data() << std::endl;
        }
        else if(argc == 4 && argv[1][0] == '-' && argv[1][1] == 'f' && argv[2][0] == '-' && argv[2][1] == 'r') {
            std::string file;
            std::cout << "Enter file path: ";
            std::cin >> file;
            std::cout << std::endl;
            Lunyx::FileIOCalls fileIoCalls = Lunyx::FileIOCalls(file);
            size_t count = static_cast<size_t>(std::atoi(argv[3]));
            std::cout << fileIoCalls.read_data(count) << std::endl;
        }
    }
    */


    std::string file("/home/neel/test/foo");

    Lunyx::FilePath fp(file);
    std::cout << "Filename is: " << fp.filename << std::endl
              << "Pathname is: " << fp.pathname << std::endl
              << "Absolute path is: " << fp.absolute_path << std::endl;

    return 0;
}