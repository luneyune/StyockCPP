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

    const auto pos = scommand.tellg();
    std::getline(scommand, token, '\n'); // Check if arguments is string
    if (token[0] == '\"') {
        for (int i = 1; token[i] != '\"'; i++)
        {
            int arg = token[i];
            retval.args.insert(retval.args.end(), arg);
        }
        retval.args.insert(retval.args.end(), '\0');
        return retval;
    }
    scommand.seekg(pos);

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

    if (parsed.mnemonic == "push") {
        return compileRaw<command::push>(parsed.args);
    }
    if (parsed.mnemonic == "pop") {
        return compileRaw<command::pop>(parsed.args);
    }

    if (parsed.mnemonic == "stop") {
        return compileRaw<command::stop>(parsed.args);
    }
    if (parsed.mnemonic == "js") {
        return compileRaw<command::js>(parsed.args);
    }
    if (parsed.mnemonic == "jmp") {
        return compileRaw<command::jmp>(parsed.args);
    }
    if (parsed.mnemonic == "jl") {
        return compileRaw<command::jl>(parsed.args);
    }
    if (parsed.mnemonic == "jle") {
        return compileRaw<command::jle>(parsed.args);
    }
    if (parsed.mnemonic == "jge") {
        return compileRaw<command::jge>(parsed.args);
    }
    if (parsed.mnemonic == "jg") {
        return compileRaw<command::jg>(parsed.args);
    }
    if (parsed.mnemonic == "je") {
        return compileRaw<command::je>(parsed.args);
    }

    return compileRaw<command::readc>(parsed.args);
}






