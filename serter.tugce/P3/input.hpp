#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstddef>
#include <iostream>

namespace serter
{
  void checkForEmptyString(const char* buffer, size_t& bufferSize);
  char* inputString(std::istream& input, size_t& bufferSize);
}

