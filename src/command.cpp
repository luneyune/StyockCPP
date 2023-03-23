#include "command.hpp"

#include <iostream>

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
    std::cin >> input;
    stack.push('\0');
    for (auto i = input.crbegin(); i != input.crend(); i++) {
        stack.push(static_cast<int>(*i));
    }
}

