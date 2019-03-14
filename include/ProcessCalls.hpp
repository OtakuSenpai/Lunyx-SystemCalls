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
    enum class Calls {
        none = -1,
        fork = 0,
        exit = 1,
        wait = 2,
    };

    class ProcessCalls {
    private:

        pid_t retValue = 0;
        Calls processCalls = Calls::none;

    public:
        ProcessCalls() {}

        ProcessCalls(const Calls& call) {
            processCalls = call;
        }

        ~ProcessCalls() {}

        void process_a_call(int argc, char* argv[]);
    };
}



#endif //LUNYX_SYSTEMCALLS_PROCESSCALLS_HPP
