#include "inputOfString.h"
#include <iomanip>
#include <stdexcept>

char *shabalin::inputOfString(std::istream &input, size_t &sizeOfString)
{
  char someCharacter = 0;
  size_t index = 0;
  char *initialString = new char[sizeOfString]();

  input >> std::noskipws;

  while (input >> someCharacter)
  {
    if (!input)
    {
      delete[] initialString;
      throw std::logic_error("Input error");
    }
    if (index == sizeOfString - 1)
    {
      try
      {
        sizeOfString *= 2;
        char *intermediateString = new char[sizeOfString]();

        for (size_t i = 0; i < index; ++i)
        {
          intermediateString[i] = initialString[i];
        }

        delete[] initialString;
        initialString = intermediateString;
      }
      catch (std::bad_alloc &e)
      {
        delete[] initialString;
        throw;
      }
    }
    initialString[index] = someCharacter;
    index++;
  }
  return initialString;
}
