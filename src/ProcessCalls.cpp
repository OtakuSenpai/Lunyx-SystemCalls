//
// Created by neel on 3/13/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <err.h>
#include <ProcessCalls.hpp>

using namespace Lunyx;

void ProcessCalls :: process_a_call(int argc, char* argv[]) {
    switch(processCalls) {
        case Calls::fork :
            std::cout << "This call forks the current process.\n";
            retValue = fork();
            if(retValue == -1) {
                err(1,"Error in ProcessCalls::process_a_call() : Couldn't fork !!!");
            }
            else if(retValue == 0)  // Code executed by child
                std::cout << "Child PID is : " << static_cast<int>(getpid());

            break;

        case Calls::exit :
            std::cout << "This call exits the current process.\n";
            exit(0);

        case Calls::wait :
            int options = 0;
            int *status = nullptr;
            pid_t p;

            retValue = fork();
            if(retValue == -1)
                err(1,"Error in ProcessCalls::process_a_call() : fork() returned -1.");

            if(retValue != -1 && retValue != 0) {
                do {
                    p = waitpid(retValue,status,WEXITED | WSTOPPED | WCONTINUED);

                    if(p == -1)
                         err(1,"Error in ProcessCalls::process_a_call() : waitpid() gave -1.");
                    if(WIFEXITED(*status))
                        std::cout << "Exit by status = " << WEXITSTATUS(*status) << std::endl;
                    else if(WIFSTOPPED(*status))
                        std::cout << "Stopped by status = " << WSTOPSIG(*status) << std::endl;
                    else if(WIFCONTINUED(*status))
                        std::cout << "Continued!!!" << std::endl;
                } while(!WIFEXITED(*status) && !WIFSIGNALED(*status));
            }

            exit(EXIT_SUCCESS);
    }
}