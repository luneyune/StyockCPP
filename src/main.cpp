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
        spp_command_ptr compiled = compiler.compile(command);
        programm.programm.insert(programm.programm.cend(), std::move(compiled));
    }
}

int main()
{
    Programm programm;
    pre_compile("etc/test.txt", programm);
    for (auto i = programm.programm.cbegin(); i != programm.programm.cend(); i++) {
        (*i)->execute(programm);
    }
}