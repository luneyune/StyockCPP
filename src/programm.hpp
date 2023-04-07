#ifndef STYOCKCPP_COMPILER_SRC_PROGRAMM_HPP_
#define STYOCKCPP_COMPILER_SRC_PROGRAMM_HPP_

#include <stack>
#include <vector>
#include <string>

#include "command.hpp"

enum State {
    RUN,
    STOP,
};

class Programm
{
public:
    spp_stack data;
    State getState();
    void setState(State state);
    
    size_t current = 0;
    void loadCommand(spp_command_ptr command);
    void executeNextCommand();

private:
    State state = RUN;
    std::vector<spp_command_ptr> programm = {};
};

#endif