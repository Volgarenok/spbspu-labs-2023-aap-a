#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <iosfwd>

namespace isaychev
{
  void copyString(const char * str, char * str2);
  char * inputString(std::istream & input, size_t & length1, size_t & capacity);
}

#endif
