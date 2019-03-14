//
// Created by neel on 3/14/19.
//

#ifndef LUNYX_SYSTEMCALLS_HELPERS_HPP
#define LUNYX_SYSTEMCALLS_HELPERS_HPP

namespace Lunyx {
    int num_of_slashes(const std::string& file) {
        int count = 0;
        for(auto c : file)
            if(c == '/') ++count;

        return count;
    }
}

#endif //LUNYX_SYSTEMCALLS_HELPERS_HPP
