#ifndef STYOCKCPP_COMPILER_SRC_INPUT_HPP_
#define STYOCKCPP_COMPILER_SRC_INPUT_HPP_

#include <cstddef>
#include <string>

class iCommand
{
public:
    virtual ~iCommand() = 0;
    virtual void execute() = 0;
};

class iCompiler
{
    virtual iCommand compile(std::string command);
};

#endif