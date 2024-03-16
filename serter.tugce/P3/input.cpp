#include "input.hpp"
#include <iostream>
#include <cstddef>
#include <stdexcept>

void serter::checkForEmptyString(const char* buffer, size_t& bufferSize)
{
    bool hasNonSpace = false;
    for (size_t i = 0; i < bufferSize; ++i)
    {
      if(buffer[i] != '\0')
      {
        if (!std::isspace(buffer[i]))
        {
          hasNonSpace = true;
          break;
        }
      }
    }
    if (!hasNonSpace)
    {
      throw std::invalid_argument("Empty string");
    }
}

char* serter::inputString(char* buffer, size_t& bufferSize)
{
  buffer = new char[bufferSize]();
  char character = 0;
  size_t index = 0;

  std::cin >> std::noskipws;

  while (std::cin >> character)
  {
    if (!std::cin)
    {
      delete[] buffer;
      throw std::runtime_error("Invalid input");
    }

    if (index < bufferSize - 1)
    {
      buffer[index++] = character;
      if (character == '\n')
      {
        buffer[index - 1] = '\0';
        break;
      }
    }
    else if (index == bufferSize - 1)
    {
      bufferSize *= 20;
      char* newBuffer = new char[bufferSize]();
      for(size_t i = 0; i < index; ++i)
      {
        newBuffer[i] = buffer[i];
      }
      delete[] buffer;
      buffer = newBuffer;
    }
  }
  serter::checkForEmptyString(buffer, bufferSize);
  return buffer;
}

