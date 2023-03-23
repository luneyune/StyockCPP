#ifndef STYOCKCPP_COMPILER_SRC_INPUT_HPP_
#define STYOCKCPP_COMPILER_SRC_INPUT_HPP_

#include <iostream>
#include <fstream>
#include <string>

class Input
{
private:
    const char* filename;
    std::ifstream fileStream;

    Input() {};
    Input(Input&) {};
public:
    ~Input();
    bool is_readable();

    static Input& getInstance(const char* filename);
    std::string readString();

};

#endif