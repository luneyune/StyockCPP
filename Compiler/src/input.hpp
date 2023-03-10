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

    static Input& getInstance(const char* filename);
    void readString(char *buffer, size_t buffsize);

};

#endif