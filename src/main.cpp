#include <iostream>
#include "input.hpp"

int main()
{
    Input &input = Input::getInstance("etc/test.txt");
    char rbuf[100];

    while (input.is_readable())
    {
        input.readString(rbuf, 100);
        std::cout << rbuf << std::endl;
    }
}