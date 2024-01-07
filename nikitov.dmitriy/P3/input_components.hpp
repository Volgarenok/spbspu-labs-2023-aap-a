#ifndef INPUT_COMPONENTS_HPP
#define INPUT_COMPONENTS_HPP

#include <iostream>

namespace nikitov
{
  size_t enterBuffer(char buffer[], std::istream& input, size_t bufferSize);

  void moveBuffer(char buffer[], char* actualArray, size_t arraySize, size_t bufferSize);

  char* increaseArray(char* actualArray, size_t arraySize, size_t bufferSize);
}
#endif
