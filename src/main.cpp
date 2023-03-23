#include <iostream>
#include <stack>
#include <vector>

#include "types.hpp"
#include "input.hpp"
#include "command.hpp"
#include "compiler.hpp"

int main()
{
    spp_stack data;
    Input &input = Input::getInstance("etc/test.txt");
    Compiler &compiler = Compiler::getInstance();

    while (input.is_readable())
    {
        std::string command = input.readString();
        spp_command_ptr to_execute = compiler.compile(command);
        to_execute->execute(data);
    }
}