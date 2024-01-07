#include <iostream>
#include "inputArray.hpp"

char * spiridonov::inputArray(std::istream& input, size_t sizeOfStr)
{
  char * currentArray = new char[sizeOfStr];
  char character = 0;
  size_t i = 0;
  input >> std::noskipws;
  while ((input >> character) && (character != '\n'))
  {
    currentArray[i] = character;
    i++;

    if (i >= sizeOfStr)
    {
      try
      {
        char* newArray = new char[sizeOfStr + 10];
        for (size_t j = 0; j < i; ++j)
        {
          newArray[j] = currentArray[j];
        }
        delete[] currentArray;
        currentArray = newArray;
        sizeOfStr += 10;
      }
      catch (...)
      {
        delete[] currentArray;
        std::cerr << "Failed allocate memory" << "\n";
        return nullptr;
      }
    }
  }
  char* finalArray = new char[i];
  for (size_t j = 0; j < i; ++j)
  {
    finalArray[j] = currentArray[j];
  }
  delete[] currentArray;
  return finalArray;
}
