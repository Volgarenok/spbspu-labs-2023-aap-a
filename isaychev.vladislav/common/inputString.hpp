#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <iosfwd>

namespace isaychev
{
  bool checkForEmptyStr(const char * str);
  char * inputString(std::istream & input, size_t & capacity);
}

#endif
