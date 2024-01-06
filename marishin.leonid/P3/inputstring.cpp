#include "inputstring.hpp"

char* marishin::inputString(std::istream& input)
{
  const size_t initialBufferSize = 10;
  char* buffer = nullptr;
  try
  {
    buffer = new char[initialBufferSize];
  }
  catch (const std::bad_alloc& ba)
  {
    delete[] buffer;
    throw ba;
  }
  size_t bufferSize = initialBufferSize;
  size_t currentIndex = 0;
  char currentChar = 0;
  while ((input >> currentChar) && (currentChar != '\n'))
  {
    if (currentIndex == (bufferSize - 1))
    {
      bufferSize *= 2;
      char* newBuffer = nullptr;
      try
      {
        newBuffer = new char[bufferSize];
      }
      catch (const std::bad_alloc& ba)
      {
        delete[] buffer;
        throw ba;
      }
      for (size_t i = 0; i < currentIndex; ++i)
      {
        newBuffer[i] = buffer[i];
      }
      delete[] buffer;
      buffer = newBuffer;
    }
    buffer[currentIndex] = currentChar;
    currentIndex++;
  }
  buffer[currentIndex] = '\0';
  if (buffer[0] == '\0')
  {
    delete[] buffer;
    throw std::logic_error("empty input!");
  }
  else
  {
    return buffer;
  }
}
