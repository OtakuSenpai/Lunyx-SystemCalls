//
// Created by neel on 3/14/19.
//

#ifndef LUNYX_SYSTEMCALLS_HELPERS_HPP
#define LUNYX_SYSTEMCALLS_HELPERS_HPP

namespace Lunyx {

    std::string find_errno(const int& error_code);

    struct FilePath {
        std::string filename;
        std::string pathname;
        std::string absolute_path;
        size_t slash_count = 0;

        FilePath(const std::string& path);
        ~FilePath() {}

        // Counts number of forward slashes in a file
        // Used in finding the directory path in FileIOCalls
        int num_of_slashes(const std::string& file);

        void cd_path(const std::string &path, const size_t& slash_count);
    };

}

#endif //LUNYX_SYSTEMCALLS_HELPERS_HPP
