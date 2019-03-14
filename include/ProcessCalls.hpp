//
// Created by neel on 3/13/19.
//

#include <stdexcept>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef LUNYX_SYSTEMCALLS_PROCESSCALLS_HPP
#define LUNYX_SYSTEMCALLS_PROCESSCALLS_HPP

namespace Lunyx {
    class ProcessCalls {
    private:

        pid_t retValue = 0;

    public:
        ProcessCalls() {}

        ~ProcessCalls() {}

        void process_a_call(int argc, char* argv[]);
    };
}



#endif //LUNYX_SYSTEMCALLS_PROCESSCALLS_HPP
