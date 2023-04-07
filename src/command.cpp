#include "command.hpp"
#include "programm.hpp"

#include <iostream>

namespace command {

// Output
void printd::execute(Programm &programm)
{
    if (programm.data.empty()) return;
    int d = programm.data.top();

    std::cout << d << std::endl;
}

void printc::execute(Programm &programm)
{
    if (programm.data.empty()) return;
    int d = programm.data.top();

    std::cout << static_cast<char>(d) << std::endl;
}

void prints::execute(Programm &programm)
{
    if (programm.data.empty()) return;
    int d = programm.data.top();
    while (d != '\0') {
        programm.data.pop();
        std::cout << static_cast<char>(d);
        d = programm.data.top();
    }
    programm.data.pop();
    std::cout << std::endl;
}

// Input
void readd::execute(Programm &programm)
{
    int d;
    std::cin >> d;
    programm.data.push(d);
}

void readc::execute(Programm &programm)
{
    char d;
    std::cin >> d;
    programm.data.push(static_cast<int>(d));
}

void reads::execute(Programm &programm)
{
    std::string input;
    std::cin >> std::ws;
    std::getline(std::cin, input, '\n');
    programm.data.push('\0');
    for (auto i = input.crbegin(); i != input.crend(); i++) {
        programm.data.push(static_cast<int>(*i));
    }
}



// Math
void add::execute(Programm &programm)
{
    if (programm.data.size() < 2) return;
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b + a);
}

void sub::execute(Programm &programm)
{
    if (programm.data.size() < 2) return;
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b - a);
}

void div::execute(Programm &programm)
{
    if (programm.data.size() < 2) return;
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b / a);
}

void mod::execute(Programm &programm)
{
    if (programm.data.size() < 2) return;
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b % a);
}

void mul::execute(Programm &programm)
{
    if (programm.data.size() < 2) return;
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b * a);
}

void cmp::execute(Programm &programm)
{
    if (programm.data.size() < 2) return;
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();

    if (a < b) {
        programm.data.push(-1);
        return;
    }
    if (a > b) {
        programm.data.push(1);
        return;
    }

    programm.data.push(0);
    return;
}



// Data operation
void push::execute(Programm &programm)
{
    if (args.empty()) {
        programm.data.push(programm.data.top());
    }
    for (auto iterator = args.crbegin(); iterator != args.crend(); iterator++) {
        programm.data.push(*iterator);
    }
}

void pop::execute(Programm &programm)
{
    if (programm.data.empty()) return;
    programm.data.pop();
}



// Control
void stop::execute(Programm &programm)
{
    programm.setState(STOP);
}

void jmp::execute(Programm &programm)
{
    if (args.empty()) return;
    programm.current = args.at(0) - 1;
}

void js::execute(Programm &programm)
{
    if (programm.data.empty()) return;
    programm.current = programm.data.top() - 1;
}


void jl::execute(Programm &programm)
{
    if (args.empty()) return;
    if (programm.data.empty()) return;
    if (!(programm.data.top() < 0)) {
        programm.data.pop();
        return;
    }
       
    programm.data.pop();
    programm.current = args.at(0) - 1;
}

void jle::execute(Programm &programm)
{
    if (args.empty()) return;
    if (programm.data.empty()) return;
    if (!(programm.data.top() <= 0)) {
        programm.data.pop();
        return;
    }
       
    programm.data.pop();
    programm.current = args.at(0) - 1;
}

void jg::execute(Programm &programm)
{
    if (args.empty()) return;
    if (programm.data.empty()) return;
    if (!(programm.data.top() > 0)) {
        programm.data.pop();
        return;
    }
       
    programm.data.pop();
    programm.current = args.at(0) - 1;
}

void jge::execute(Programm &programm)
{
    if (args.empty()) return;
    if (programm.data.empty()) return;

    if (!(programm.data.top() >= 0)) {
        programm.data.pop();
        return;
    }
       
    programm.data.pop();
    programm.current = args.at(0) - 1;
}

void je::execute(Programm &programm)
{
    if (args.empty()) return;
    if (programm.data.empty()) return;

    if (programm.data.top() != 0) {
        programm.data.pop();
        return;
    }
       
    programm.data.pop();
    programm.current = args.at(0) - 1;
}

};
