#include "command.hpp"

#include <iostream>

namespace command {
// Output
void printd::execute(spp_stack &stack)
{
    int d = stack.top();
    stack.pop();

    std::cout << d << std::endl;
}

void printc::execute(spp_stack &stack)
{
    int d = stack.top();
    stack.pop();

    std::cout << static_cast<char>(d) << std::endl;
}

void prints::execute(spp_stack &stack)
{
    int d = stack.top();
    while (d != '\0') {
        stack.pop();
        std::cout << static_cast<char>(d);
        d = stack.top();
    }
    stack.pop();
    std::cout << std::endl;
}



// Input
void readd::execute(spp_stack &stack)
{
    int d;
    std::cin >> d;
    stack.push(d);
}

void readc::execute(spp_stack &stack)
{
    char d;
    std::cin >> d;
    stack.push(static_cast<int>(d));
}

void reads::execute(spp_stack &stack)
{
    std::string input;
    std::cin >> std::ws;
    std::getline(std::cin, input, '\n');
    stack.push('\0');
    for (auto i = input.crbegin(); i != input.crend(); i++) {
        stack.push(static_cast<int>(*i));
    }
}


// Math

void add::execute(spp_stack &stack)
{
    int a = stack.top();
    stack.pop();

    int b = stack.top();
    stack.pop();

    stack.push(b + a);
}

void sub::execute(spp_stack &stack)
{
    int a = stack.top();
    stack.pop();

    int b = stack.top();
    stack.pop();

    stack.push(b - a);
}

void div::execute(spp_stack &stack)
{
    int a = stack.top();
    stack.pop();

    int b = stack.top();
    stack.pop();

    stack.push(b / a);
}

void mod::execute(spp_stack &stack)
{
    int a = stack.top();
    stack.pop();

    int b = stack.top();
    stack.pop();

    stack.push(b % a);
}

void mul::execute(spp_stack &stack)
{
    int a = stack.top();
    stack.pop();

    int b = stack.top();
    stack.pop();

    stack.push(b * a);
}

void cmp::execute(spp_stack &stack)
{
    int a = stack.top();
    stack.pop();

    int b = stack.top();
    stack.pop();

    if (a > b) {
        stack.push(-1);
        return;
    }
    if (a < b) {
        stack.push(1);
        return;
    }

    stack.push(0);
    return;
}

};
