#ifndef INPUT_STR_HPP
#define INPUT_STR_HPP
#include <cstddef>
#include <iostream>

namespace grechishnikov
{
  char* inputStr(std::istream& in, size_t& size);
  char* reallocate(char* str, size_t lenF, size_t lenS);
}

#endif
