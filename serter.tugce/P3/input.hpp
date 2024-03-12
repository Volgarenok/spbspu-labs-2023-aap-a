#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstddef>

namespace serter
{

  void checkForEmptyString(const char* buffer);

  void inputString(char* buffer, size_t bufferSize);

  void expandBuffer(char* buffer, size_t& bufferSize, size_t currentIndex);

}
#endif

