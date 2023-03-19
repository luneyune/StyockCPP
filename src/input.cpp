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

void Input::readString(char *buffer, size_t buffsize)
{
    fileStream.getline(buffer, buffsize);
}

