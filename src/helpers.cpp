//
// Created by neel on 3/15/19.
//

#include <string>
#include "helpers.hpp"

int Lunyx::num_of_slashes(const std::string& file) {
    int count = 0;
    for(auto c : file)
        if(c == '/') ++count;

    return count;
}