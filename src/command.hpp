#ifndef STYOCKCPP_COMPILER_SRC_COMMAND_HPP_
#define STYOCKCPP_COMPILER_SRC_COMMAND_HPP_

#include <cstddef>
#include <string>
#include <stack>
#include <vector>

#include "types.hpp"

struct Programm;

// Interface class for all commands
class iCommand
{
protected:
    std::vector<int> args;
public:
    iCommand(std::vector<int> args = {}) { this->args = args; }
    virtual ~iCommand() {}
    virtual void execute(Programm &programm) = 0;
};


namespace command {
// Command Classes

// Output
class printd : public iCommand
{
public:
    printd(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class printc : public iCommand
{
public:
    printc(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class prints : public iCommand
{
public:
    prints(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};



// Input
class readd : public iCommand
{
public:
    readd(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class readc : public iCommand
{
public:
    readc(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class reads : public iCommand
{
public:
    reads(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};


// Math
class add : public iCommand
{
public:
    add(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class sub : public iCommand
{
public:
    sub(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class div : public iCommand
{
public:
    div(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class mod : public iCommand
{
public:
    mod(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class mul : public iCommand
{
public:
    mul(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class cmp : public iCommand
{
public:
    cmp(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

// Data opertation

class push : public iCommand
{
public:
    push(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};

class pop : public iCommand
{
public:
    pop(std::vector<int> args = {}) : iCommand(args) {}
    void execute(Programm &programm) override;
};


};

#endif