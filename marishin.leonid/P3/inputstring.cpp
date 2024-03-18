#include "inputstring.hpp"

char* marishin::inputString(std::istream& input)
{
  size_t initialBufferSize = 10;
  size_t currentIndex = 0;
  char* buffer = new char[initialBufferSize];
  char currentChar = 0;
  while ((input >> currentChar) && (currentChar != '\n'))
  {
    if (currentIndex + 1 == initialBufferSize)
    {
      try
      {
        char* newBuffer = new char[initialBufferSize + 10];
        for (size_t i = 0; i < initialBufferSize; ++i)
        {
          newBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = newBuffer;
        initialBufferSize += 10;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] buffer;
        throw;
      }
    }
    buffer[currentIndex] = currentChar;
    currentIndex++;
  }
  buffer[currentIndex] = '\0';
  return buffer;
}
