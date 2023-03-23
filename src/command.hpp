#ifndef STYOCKCPP_COMPILER_SRC_COMMAND_HPP_
#define STYOCKCPP_COMPILER_SRC_COMMAND_HPP_

#include <cstddef>
#include <string>
#include <stack>
#include <vector>

#include "types.hpp"

// Interface class for all commands
class iCommand
{
private:
    std::vector<int> args;
public:
    iCommand(std::vector<int> args = {}) { this->args = args; }
    virtual ~iCommand() {}
    virtual void execute(spp_stack &stack) = 0;
};

// Command Classes

// Output
class printd : public iCommand
{
public:
    printd(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

class printc : public iCommand
{
public:
    printc(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

class prints : public iCommand
{
public:
    prints(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};



// Input
class readd : public iCommand
{
public:
    readd(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

class readc : public iCommand
{
public:
    readc(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

class reads : public iCommand
{
public:
    reads(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

#endif