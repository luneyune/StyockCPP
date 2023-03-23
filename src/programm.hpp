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

class Programm
{
private:
    spp_stack data;
    std::vector<iCommand> programm;
    Programm() {};
    Programm(Programm&) {};
public:
    Programm &getInstance();
    State executeNextCommand();
};

#endif