#include "programm.hpp"

#include "input.hpp"
#include "compiler.hpp"

Programm::Programm(const char *filename)
{
    Input &input = Input::getInstance(filename);
    Compiler &compiler = Compiler::getInstance();

    while (input.is_readable())
    {
        std::string command = input.readString();
        if (command.empty()) continue;

        spp_command_ptr compiled = compiler.compile(command);
        loadCommand(std::move(compiled));
    }
}

State Programm::getState()
{
    return state;
}

void Programm::setState(State state)
{
    this->state = state;
}

void Programm::loadCommand(spp_command_ptr command)
{
    programm.insert(programm.cend(), std::move(command));
}

void Programm::executeNextCommand()
{
    if (current >= programm.size())
    {
        state = STOP;
        return;
    }
    
    programm.at(current)->execute(*this);
    current++;
}