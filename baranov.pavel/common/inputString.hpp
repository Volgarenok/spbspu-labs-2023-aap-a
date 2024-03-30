#ifndef INPUT_STRING_HPP
#define INPUT_STRING_HPP
#include <iostream>

namespace baranov
{
  char * expandString(const char * string, size_t newSize);
  char * inputString(std::istream & input, size_t & stringSize);
}

#endif

