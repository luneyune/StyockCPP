#include <sstream>

#include "compiler.hpp"
#include "command.hpp"
#include "types.hpp"

Compiler::Compiler()
{
    compile_map.insert({"printc", [](std::vector<int> args) { return std::make_unique<command::printc>(args); }});
    compile_map.insert({"printd", [](std::vector<int> args) { return std::make_unique<command::printd>(args); }});
    compile_map.insert({"prints", [](std::vector<int> args) { return std::make_unique<command::prints>(args); }});

    compile_map.insert({"reads", [](std::vector<int> args) { return std::make_unique<command::reads>(args); }});
    compile_map.insert({"readd", [](std::vector<int> args) { return std::make_unique<command::readd>(args); }});
    compile_map.insert({"readc", [](std::vector<int> args) { return std::make_unique<command::readc>(args); }});

    compile_map.insert({"add", [](std::vector<int> args) { return std::make_unique<command::add>(args); }});
    compile_map.insert({"sub", [](std::vector<int> args) { return std::make_unique<command::sub>(args); }});
    compile_map.insert({"mul", [](std::vector<int> args) { return std::make_unique<command::mul>(args); }});
    compile_map.insert({"div", [](std::vector<int> args) { return std::make_unique<command::div>(args); }});
    compile_map.insert({"mod", [](std::vector<int> args) { return std::make_unique<command::mod>(args); }});
    compile_map.insert({"cmp", [](std::vector<int> args) { return std::make_unique<command::cmp>(args); }});

    compile_map.insert({"push", [](std::vector<int> args) { return std::make_unique<command::push>(args); }});
    compile_map.insert({"pop", [](std::vector<int> args) { return std::make_unique<command::pop>(args); }});

    compile_map.insert({"stop", [](std::vector<int> args) { return std::make_unique<command::stop>(args); }});
    compile_map.insert({"jmp", [](std::vector<int> args) { return std::make_unique<command::jmp>(args); }});
    compile_map.insert({"js", [](std::vector<int> args) { return std::make_unique<command::js>(args); }});

    compile_map.insert({"jle", [](std::vector<int> args) { return std::make_unique<command::jle>(args); }});
    compile_map.insert({"jge", [](std::vector<int> args) { return std::make_unique<command::jge>(args); }});
    compile_map.insert({"jl", [](std::vector<int> args) { return std::make_unique<command::jl>(args); }});
    compile_map.insert({"jg", [](std::vector<int> args) { return std::make_unique<command::jg>(args); }});
    compile_map.insert({"je", [](std::vector<int> args) { return std::make_unique<command::je>(args); }});
}

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

spp_command_ptr Compiler::compile(const std::string &command)
{
    strCommand parsed = parseCommand(command);

    if (compile_map.find(parsed.mnemonic) != compile_map.cend()) {
        return compile_map[parsed.mnemonic](parsed.args);
    }

    return compile_map["readc"](parsed.args);

}






