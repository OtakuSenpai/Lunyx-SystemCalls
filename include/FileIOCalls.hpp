//
// Created by neel on 3/14/19.
//

#ifndef LUNYX_SYSTEMCALLS_FILEIOCALLS_HPP
#define LUNYX_SYSTEMCALLS_FILEIOCALLS_HPP

#include <string>

#include "helpers.hpp"

namespace Lunyx {
    class FileIOCalls {
    private:
        std::string filename;
        size_t file_desc = 0;

    public:
        FileIOCalls() {}

        FileIOCalls(const std::string& file);

        void write();

        std::string& read();
    };
}

#endif //LUNYX_SYSTEMCALLS_FILEIOCALLS_HPP
