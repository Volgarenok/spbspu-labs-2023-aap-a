#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstddef>

namespace serter
{
  void checkForEmptyString(const char* buffer, size_t& bufferSize);
  char* inputString(char* buffer, size_t& bufferSize);
}
#endif

