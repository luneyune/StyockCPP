#ifndef STYOCKCPP_COMPILER_SRC_PROGRAMM_HPP_
#define STYOCKCPP_COMPILER_SRC_PROGRAMM_HPP_

#include <stack>
#include <vector>
#include <string>

#include "command.hpp"

enum class State {
    RUN,
    STOP,
};

class Programm
{
public:
    Programm(const char *filename);

    spp_stack data;
    State getState();
    
    size_t current = 0;
    bool executeNextCommand();

private:
    void loadCommand(spp_command_ptr command);
    State state = State::RUN;
    std::vector<spp_command_ptr> programm = {};


    friend class command::stop;
};

#endif