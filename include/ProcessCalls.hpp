//
// Created by neel on 3/13/19.
//

#include <sys/types.h>
#include <unistd.h>

#ifndef LUNYX_SYSTEMCALLS_PROCESSCALLS_HPP
#define LUNYX_SYSTEMCALLS_PROCESSCALLS_HPP

enum class Calls {
    none(-1),
    fork(0),
    exit(1),
    wait(2);
};

class ProcessCalls {
private:
    int retValue = 0;
    Calls processCalls = Calls()

};



#endif //LUNYX_SYSTEMCALLS_PROCESSCALLS_HPP
