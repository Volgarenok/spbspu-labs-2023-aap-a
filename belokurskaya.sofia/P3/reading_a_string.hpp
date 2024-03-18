#ifndef READING_A_STRING_HPP
#define READING_A_STRING_HPP

#include <iostream>
#include <stdexcept>

namespace belokurskaya
{
  char* resizeStringBuffer(const char* my_string, size_t size, size_t new_memory);

  char* inputString(std::istream& input);
}

#endif
