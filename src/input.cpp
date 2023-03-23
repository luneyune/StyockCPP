#include "input.hpp"

Input& Input::getInstance(const char* filename)
{
    static Input input;
    input.filename = filename;
    input.fileStream.open(filename);

    return input;
}

Input::~Input()
{
    fileStream.close();
}

bool Input::is_readable()
{
    return fileStream.good();
}

std::string Input::readString()
{
    char buffer[120];
    fileStream.getline(buffer, 120);
    std::string line(buffer);
    return line;
}

