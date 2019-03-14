//
// Created by neel on 3/13/19.
//
#include <iostream>
#include "include/ProcessCalls.hpp"

int main(int argc, char** argv) {
    Lunyx::ProcessCalls processCalls;
    Lunyx::Calls calls = Lunyx::Calls::none;

    if(argc < 1) {
        std::cout << "Options are: \n";
        std::cout << " For ProcessCalls: \n"
                  << " 1 - Fork \n"
                  << " 2 - Exit \n"
                  << " 3 - Wait \n";
    } else if(argc > 1) {
        if(argc == 3 && *argv[2] == '-' && *argv[3] == 'h') {
            std::cout << "Options are: \n";
            std::cout << " For ProcessCalls: \n"
                      << " 1 - Fork \n"
                      << " 2 - Exit \n"
                      << " 3 - Wait \n";
        }
        else if(argc == 4 && *argv[2] == '-' && *argv[3] == 'p') {
            if(static_cast<int>(*argv[3]) == 1) calls = Lunyx::Calls::fork;
            else if(static_cast<int>(*argv[3]) == 2) calls = Lunyx::Calls::exit;
            else if(static_cast<int>(*argv[3]) == 3) calls = Lunyx::Calls::wait;
            else throw std::runtime_error("Error in main() : Unable to comprehend the CallID!!!");

            processCalls = Lunyx::ProcessCalls(calls);

            processCalls.process_a_call(argc,argv);
        }
    }

    return 0;
}