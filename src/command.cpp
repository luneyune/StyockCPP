#include "command.hpp"
#include "programm.hpp"

#include <iostream>

namespace command {
// Output
void printd::execute(Programm &programm)
{
    int d = programm.data.top();
    programm.data.pop();

    std::cout << d << std::endl;
}

void printc::execute(Programm &programm)
{
    int d = programm.data.top();
    programm.data.pop();

    std::cout << static_cast<char>(d) << std::endl;
}

void prints::execute(Programm &programm)
{
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
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b + a);
}

void sub::execute(Programm &programm)
{
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b - a);
}

void div::execute(Programm &programm)
{
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b / a);
}

void mod::execute(Programm &programm)
{
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b % a);
}

void mul::execute(Programm &programm)
{
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    programm.data.push(b * a);
}

void cmp::execute(Programm &programm)
{
    int a = programm.data.top();
    programm.data.pop();

    int b = programm.data.top();
    programm.data.pop();

    if (a > b) {
        programm.data.push(-1);
        return;
    }
    if (a < b) {
        programm.data.push(1);
        return;
    }

    programm.data.push(0);
    return;
}

};
