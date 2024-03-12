#include "input.hpp"
#include <iostream>
#include <cstddef>
#include <stdexcept>

void serter::checkForEmptyString(const char* buffer)
{
  bool hasNonSpace = false;
  for (size_t i = 0; buffer[i] != '\0'; ++i)
  {
    if (!std::isspace(buffer[i]))
    {
      hasNonSpace = true;
      break;
    }
  }
  if (!hasNonSpace)
  {
    throw std::invalid_argument("Empty string");
  }
}

void serter::inputString(char* buffer, size_t bufferSize)
{
  char character = 0;
  size_t index = 0;

  std::cin >> std::noskipws;

  while (std::cin >> character)
  {
    if (!std::cin)
    {
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
    else
    {
      break;
    }
  }
  serter::checkForEmptyString(buffer);
}

void serter::expandBuffer(char* buffer, size_t& bufferSize, size_t currentIndex)
{
  const size_t newBufferSize = bufferSize * 2;
  char* newBuffer = nullptr;
  try
  {
    newBuffer = new char[newBufferSize]();
  }
  catch (const std::bad_alloc&)
  {
    throw;
  }
  for (size_t k = 0; k < currentIndex; ++k)
  {
    newBuffer[k] = buffer[k];
  }
  delete[] buffer;
  buffer = newBuffer;
  bufferSize = newBufferSize;
}

