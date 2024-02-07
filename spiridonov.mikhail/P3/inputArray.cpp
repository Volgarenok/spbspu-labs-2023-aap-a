#include "inputArray.hpp"
#include <iostream>

char* spiridonov::inputArray(std::istream& input, size_t& sizeOfStr)
{
  const size_t chunkSize = 10;
  char* currentArray = nullptr;

  try
  {
    currentArray = new char[chunkSize]();
    size_t capacity = chunkSize;

    char character = 0;
    size_t i = 0;

    input >> std::noskipws;

    while (input >> character && character != '\n')
    {
      if (i >= capacity - 1)
      {
        capacity += chunkSize;
        char* newArray = new char[capacity]();
        std::copy(currentArray, currentArray + i, newArray);
        delete[] currentArray;
        currentArray = newArray;
      }

      currentArray[i] = character;
      i++;
    }

    if (i == 0 || currentArray[0] == '\n')
    {
      delete[] currentArray;
      throw;
    }

    sizeOfStr = i;
    currentArray[i] = '\0';

    return currentArray;
  }
  catch (const std::bad_alloc&)
  {
    delete[] currentArray;
    throw;
  }
}
