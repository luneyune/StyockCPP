#include <iostream>
#include <stack>
#include <vector>

#include "types.hpp"
#include "input.hpp"
#include "command.hpp"
#include "compiler.hpp"
#include "programm.hpp"

void pre_compile(const char *filename, Programm &programm)
{
    Input &input = Input::getInstance(filename);
    Compiler &compiler = Compiler::getInstance();

    while (input.is_readable())
    {
        std::string command = input.readString();
        if (command.empty()) continue;

        spp_command_ptr compiled = compiler.compile(command);
        programm.loadCommand(std::move(compiled));
    }
}

int main()
{
    Programm programm;
    pre_compile("etc/test.txt", programm);
    while (programm.getState() == RUN)
    {
        programm.executeNextCommand();
    }
}