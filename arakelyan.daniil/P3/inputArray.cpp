#include "inputArray.hpp"
#include <cstddef>
#include <stdexcept>

char * arakelyan::inputArray(std::istream &input)
{
  size_t arrSize = 10;

  size_t i = 0;
  char sym = 0;

  char * mainBuffer = nullptr;
  mainBuffer = new char[arrSize];
  if (mainBuffer == nullptr)
  {
    throw std::bad_alloc();
  }

  input >> std::noskipws;
  while ((input >> sym) && (sym != '\n'))
  {
    if (!input)
    {
      delete [] mainBuffer;
      throw std::logic_error("Input error!");
    }

    if (i == (arrSize - 1))
    {
      arrSize *= 2;

      char * tempBuffer = nullptr;

      tempBuffer = new char[arrSize];
      if (tempBuffer == nullptr)
      {
        delete [] mainBuffer;
        throw std::bad_alloc();
      }

      for (size_t j = 0; j < i; j++)
      {
        tempBuffer[j] = mainBuffer[j];
      }

      delete [] mainBuffer;

      mainBuffer = tempBuffer;
    }
    mainBuffer[i] = sym;
    i++;
  }
  mainBuffer[i] = '\0';

  if (mainBuffer[0] == '\0')
  {
    delete [] mainBuffer;
    throw std::logic_error("Empty input!");
  }

  input >> std::skipws;
  return mainBuffer;
}
