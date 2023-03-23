#include <sstream>

#include "compiler.hpp"
#include "command.hpp"
#include "types.hpp"

Compiler& Compiler::getInstance()
{
    static Compiler compiler;
    return compiler;
}

strCommand Compiler::parseCommand(const std::string &command)
{
    strCommand retval = {};
    std::istringstream scommand(command);
    std::string token;

    std::getline(scommand, token, ' '); // Pass the mnemonic of a command
    retval.mnemonic = token;

    while(std::getline(scommand, token, ' ')) {
        int number = std::stoi(token);
        retval.args.insert(retval.args.end(), number);
    }

    return retval;
}

template <typename T>
spp_command_ptr Compiler::compileRaw(std::vector<int> args)
{
    return std::make_unique<T>(args);
}


spp_command_ptr Compiler::compile(const std::string &command)
{
    strCommand parsed = parseCommand(command);
    if (parsed.mnemonic == "printd") {
        return compileRaw<printd>(parsed.args);
    }
    if (parsed.mnemonic == "printc") {
        return compileRaw<printc>(parsed.args);
    }
    if (parsed.mnemonic == "prints") {
        return compileRaw<prints>(parsed.args);
    }

    if (parsed.mnemonic == "readd") {
        return compileRaw<readd>(parsed.args);
    }
    if (parsed.mnemonic == "readc") {
        return compileRaw<readc>(parsed.args);
    }
    if (parsed.mnemonic == "reads") {
        return compileRaw<reads>(parsed.args);
    }

    return compileRaw<readc>(parsed.args);
}






