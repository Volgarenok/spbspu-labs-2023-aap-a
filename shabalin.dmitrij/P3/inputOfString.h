#ifndef INPUTOFSTRING_H
#define INPUTOFSTRING_H
#include <iostream>
#include <cstddef>

namespace shabalin
{
char* inputOfString(std::istream& input, char* initialString, size_t& initialSize);
}

#endif