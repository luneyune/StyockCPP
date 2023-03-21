#ifndef STYOCKCPP_COMPILER_SRC_PROGRAMM_HPP_
#define STYOCKCPP_COMPILER_SRC_PROGRAMM_HPP_

#include <stack>
#include <vector>
#include "command.hpp"

enum State {
    RUN,
    END,
};

class Programm
{
private:
    std::stack<int, std::vector<int>> data;
    std::vector<iCommand> programm;
    Programm() {};
    Programm(Programm&) {};

    iCommand compile(char *string, size_t buffsize);
public:
    Programm &getInstance();
    State executeNextCommand();
};

#endif