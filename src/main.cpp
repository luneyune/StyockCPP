#include <iostream>
#include <stack>
#include <vector>

#include "input.hpp"

int main()
{
    Input &input = Input::getInstance("etc/test.txt");
 
    while (input.is_readable())
    {
        
        std::cout << input.readString() << std::endl;
    }
}