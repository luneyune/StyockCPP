#include "programm.hpp"

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