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
        Lunyx::FilePath fp;
        size_t file_desc = 0;

    public:
        FileIOCalls(const std::string& file);

        ~FileIOCalls();

        size_t write_data(const std::string& input);

        std::string& read_data();

        std::string& read_data(size_t count);
    };
}

#endif //LUNYX_SYSTEMCALLS_FILEIOCALLS_HPP
