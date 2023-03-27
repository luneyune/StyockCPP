#ifndef STYOCKCPP_COMPILER_SRC_PROGRAMM_HPP_
#define STYOCKCPP_COMPILER_SRC_PROGRAMM_HPP_

#include <stack>
#include <vector>
#include <string>

#include "command.hpp"

enum State {
    RUN,
    END,
};

struct Programm
{
    spp_stack data;
    std::vector<spp_command_ptr> programm = {};
    size_t current = 0;
    State state = RUN;
};

#endif