#ifndef STYOCKCPP_COMPILER_SRC_COMPILER_HPP_
#define STYOCKCPP_COMPILER_SRC_COMPILER_HPP_

#include <memory>
#include <map>
#include "command.hpp"
#include "types.hpp"

struct strCommand
{
    std::string mnemonic;
    std::vector<int> args;
};

class Compiler
{
private:
    strCommand parseCommand(const std::string &command);
    
    template <typename T>
    spp_command_ptr compileRaw(std::vector<int> args = {});

    Compiler() {}
    Compiler(Compiler&) {}
public:
    ~Compiler() {}

    static Compiler& getInstance();
    spp_command_ptr compile(const std::string &command);
};


#endif