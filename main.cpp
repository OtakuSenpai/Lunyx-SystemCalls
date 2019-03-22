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

    Lunyx::ProcessCalls processCalls;
    int i = 0;
    std::string data;
    bool readIt = false;

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
                  << "       Subcase Read(-r): Read data from file. Argument 4 is filepath.\n"
                  << "       Example: lunyx -f -r -fp /home/neel/test/foo -c 6\n"
                  << "       Subcase Write(-w):  Write data to file. Argument 4 is filepath,\n"
                  << "       argument 6 is actual data.\n"
                  << "       Example: lunyx -f -w -fp /home/neel/test/foo -d fdbdfgdf\n";
    } else if(argc > 1) {
        if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
            std::cout << "Options are: \n";
            std::cout << " -h -> Help section.\n"
                      << " -p -> Run the process calls.\n"
                      << " -f -> Run the file i/o calls. Here the options are 'w' and 'r'.\n"
                      << "       Subcase Read(-r): Read data from file. Argument 4 is filepath.\n" <<  std::endl
                      << "       Example: lunyx -f -r -fp /home/neel/test/foo -c 6\n"
                      << "       Subcase Write(-w):  Write data to file. Argument 4 is filepath,\n"
                      << "       argument 6 is actual data.\n"
                      << "       Example: lunyx -f -w -fp /home/neel/test/foo -d fdbdfgdf\n";
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
        else if(argc == 5 && argv[1][0] == '-' && argv[1][1] == 'f' && argv[2][0] == '-' && argv[2][1] == 'r' && argv[3][0] == '-'
                && argv[3][1] == 'f' && argv[3][2] == 'p' && argv[5][0] == '-' && argv[5][1] == 'c') {
            std::string file = std::string(argv[4]);
            Lunyx::FileIOCalls fileIoCalls = Lunyx::FileIOCalls(file);
            fileIoCalls.cd_path();
            data = fileIoCalls.read_data(std::atoi(argv[6]));
            readIt = true;
        }
    }

    if(readIt)
        std::cout << "Data is: " << data << std::endl;

    return 0;
}