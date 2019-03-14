//
// Created by neel on 3/13/19.
//
#include <iostream>
#include "include/ProcessCalls.hpp"

int main(int argc, char** argv) {
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
                  << " -p -> Run the process calls.\n";
    } else if(argc > 1) {
        if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
            std::cout << "Options are: \n";
            std::cout << " -h -> Help section.\n"
                      << " -p -> Run the process calls.\n";
        }
        else if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'p') {
            processCalls = Lunyx::ProcessCalls();

            processCalls.process_a_call(argc,argv);
        }
    }

    return 0;
}