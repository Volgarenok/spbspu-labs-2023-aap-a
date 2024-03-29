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

char* serter::inputString(std::istream& input, size_t& bufferSize)
{
  char* buffer = new char[bufferSize] {};

  char character = 0;
  size_t index = 0;

  input >> std::noskipws;

  while (input >> character)
  {
    if (!input)
    {
      throw std::runtime_error("Invalid input");
    }

    if (index == bufferSize - 1)
    {
      bufferSize += 20;
      char* tempBuffer = new char[bufferSize] {};

      for (size_t j = 0; j < index; j++)
      {
        tempBuffer[j] = buffer[j];
      }

      delete[] buffer;
      buffer = tempBuffer;
    }

    buffer[index] = character;
    index++;

    if (character == '\n')
    {
      buffer[index - 1] = '\0';
      break;
    }

  }
  serter::checkForEmptyString(buffer, bufferSize);
  return buffer;
}

