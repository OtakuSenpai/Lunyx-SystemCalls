//
// Created by neel on 3/13/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <ProcessCalls.hpp>

using namespace Lunyx;

void ProcessCalls :: process_a_call(int argc, char* argv[]) {
    int options = 0;
    int status;
    pid_t p;

    std::cout << "\n\n\n"
              << "This function first calls a fork().\n"
              << "If the fork() return value(which we store in a variable named \"retValue\") is -1, then an error happened.\n"
              << "Else if it's 0, the child process is created out of the original process(via a fork()).\n"
              << "Inside the child process we pause for a moment to accept a signal(say SIGTERM or SIGKILL) \n"
              << "and exit using that signal.\n"
              << "Else if return value of fork is not 0, then it's occuring in the parent process.\n"
              << "We use another variable named 'p' to store the waitpid() return value. waitpid() stops the\n"
              << "current thread until a child process specified by the call stops or has changed state.\n"
              << "So if 'p' is -1, an error has occured. Else we check for the three states which we oversee\n"
              << "namely WEXITED, WSTOPPED and WCONTINUED using the appropriate functions and print the result.\n";

    std::cout << "Parent PID is : " << static_cast<int>(getpid()) << std::endl;

    retValue = fork();
    if(retValue == -1) {
        std::runtime_error("Error in ProcessCalls::process_a_call() : Couldn't fork !!!");
    }

    // Code executed in Child process

    else if(retValue == 0) {
        std::cout << "Child PID is : " << static_cast<int>(getpid()) << std::endl;
        if(argc == 1)
            sleep(10 * 60 * 60);
        exit(std::atoi(argv[1]));
    }


    // Code executed in parent process

    else {
        do {
            p = waitpid(retValue, &status, WEXITED | WSTOPPED | WCONTINUED);
            if (p == -1)
               std::runtime_error("Error in ProcessCalls::process_a_call() : waitpid() gave -1.");
            if (WIFEXITED(status))
                std::cout << "Exit by status = " << WEXITSTATUS(status) << std::endl;
            else if (WIFSTOPPED(status))
                std::cout << "Stopped by status = " << WSTOPSIG(status) << std::endl;
            else if (WIFCONTINUED(status))
                std::cout << "Continued!!!" << std::endl;
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    std::cout << "Call finished." << std::endl;
    exit(EXIT_SUCCESS);
}