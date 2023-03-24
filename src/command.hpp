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


namespace command {
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


// Math
class add : public iCommand
{
public:
    add(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

class sub : public iCommand
{
public:
    sub(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

class div : public iCommand
{
public:
    div(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

class mod : public iCommand
{
public:
    mod(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

class mul : public iCommand
{
public:
    mul(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};

class cmp : public iCommand
{
public:
    cmp(std::vector<int> args = {}) : iCommand(args) {}
    void execute(spp_stack &stack) override;
};


};

#endif