#include <iostream>
#include <stack>
#include <vector>

#include "types.hpp"
#include "input.hpp"
#include "command.hpp"
#include "compiler.hpp"
#include "programm.hpp"

int main()
{
    Programm programm("etc/example.txt");
    while (programm.executeNextCommand());
}