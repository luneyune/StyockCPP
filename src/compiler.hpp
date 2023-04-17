#ifndef STYOCKCPP_COMPILER_SRC_COMPILER_HPP_
#define STYOCKCPP_COMPILER_SRC_COMPILER_HPP_

#include <memory>
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
    spp_compiler compile_map = {};
    strCommand parseCommand(const std::string &command);

    Compiler();
    Compiler(Compiler&) {}
public:
    ~Compiler() {}

    static Compiler& getInstance();
    spp_command_ptr compile(const std::string &command);
};


#endif