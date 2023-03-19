#include <iostream>
#include <stack>
#include <vector>

#include "input.hpp"
#include "stack.hpp"

int main()
{
    Input &input = Input::getInstance("etc/test.txt");
    char rbuf[100];
    //std::stack<int, std::vector<int>> Stack;
 
    while (input.is_readable())
    {
        input.readString(rbuf, 100);
        std::cout << rbuf << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        Stack.push(i);
        std::cout << Stack.top() << std::endl;
        Stack.pop();
    }


}