#include "inputArray.hpp"

size_t inputArray(std::ifstream & input, int * array, size_t size, size_t sizeToRead)
{
  for (size_t i = 0; i < std::min(size, sizeToRead); ++i)
  {
    input >> array[i];
    if (!input)
    {
      return i;
    }
  }
  return std::min(size, sizeToRead);
}
