#ifndef STYOCKCPP_COMPILER_SRC_INPUT_HPP_
#define STYOCKCPP_COMPILER_SRC_INPUT_HPP_

class iCommand;

class iCompiler
{
public:
    virtual iCommand compile(char *buf, size_t buffsize);
};

class iCommand
{
public:
    virtual Command() = 0;
    virtual Command(int *args, size_t argsCount) = 0;
    virtual ~Command() = 0;

    virtual void execute() = 0;
}



#endif