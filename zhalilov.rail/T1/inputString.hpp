#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <iostream>

namespace zhalilov
{
  char *inputString(std::istream &in);
  char *resizeString(char string[], size_t oldSize, size_t newSize);
}

#endif
