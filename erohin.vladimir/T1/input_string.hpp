#ifndef INPUT_STRING_HPP
#define INPUT_STRING_HPP

#include <iosfwd>

namespace erohin
{
  char* inputString(std::istream& input, char* str);
  char* resize(char* str, size_t size, size_t shift);
}

#endif
