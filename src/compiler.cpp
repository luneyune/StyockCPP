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
        return compileRaw<command::printd>(parsed.args);
    }
    if (parsed.mnemonic == "printc") {
        return compileRaw<command::printc>(parsed.args);
    }
    if (parsed.mnemonic == "prints") {
        return compileRaw<command::prints>(parsed.args);
    }

    if (parsed.mnemonic == "readd") {
        return compileRaw<command::readd>(parsed.args);
    }
    if (parsed.mnemonic == "readc") {
        return compileRaw<command::readc>(parsed.args);
    }
    if (parsed.mnemonic == "reads") {
        return compileRaw<command::reads>(parsed.args);
    }

    if (parsed.mnemonic == "add") {
        return compileRaw<command::add>(parsed.args);
    }
    if (parsed.mnemonic == "sub") {
        return compileRaw<command::sub>(parsed.args);
    }
    if (parsed.mnemonic == "div") {
        return compileRaw<command::div>(parsed.args);
    }
    if (parsed.mnemonic == "mod") {
        return compileRaw<command::mod>(parsed.args);
    }
    if (parsed.mnemonic == "mul") {
        return compileRaw<command::mul>(parsed.args);
    }
    if (parsed.mnemonic == "cmp") {
        return compileRaw<command::cmp>(parsed.args);
    }

    return compileRaw<command::readc>(parsed.args);
}






