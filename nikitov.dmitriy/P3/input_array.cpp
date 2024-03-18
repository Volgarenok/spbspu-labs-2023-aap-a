#include "input_array.hpp"
#include <limits>
#include <stdexcept>

size_t enterBuffer(char buffer[], std::istream& input, size_t bufferSize)
{
  char symb = 0;
  size_t i = 0;
  while ((i != bufferSize) && (input >> symb))
  {
    buffer[i++] = symb;
    if (symb == '\n')
    {
      return i;
    }
  }
  if (!input)
  {
    return i;
  }
  return bufferSize;
}

void moveBuffer(const char buffer[], char* actualArray, size_t arraySize, size_t bufferSize)
{
  size_t position = arraySize;
  for (size_t j = 0; j != bufferSize; ++j)
  {
    if (buffer[j] == '\n')
    {
      break;
    }
    actualArray[position] = buffer[j];
    ++position;
  }
}

char* increaseArray(char* actualArray, size_t arraySize, size_t bufferSize)
{
  char* newArray = new char[arraySize + bufferSize]{};
  for (size_t j = 0; j != arraySize; ++j)
  {
    newArray[j] = actualArray[j];
  }
  return newArray;
}

std::pair< char*, size_t > nikitov::inputArray(std::istream& input)
{
  constexpr size_t bufferSize = 25;
  size_t actualSize = 0;

  char* actualArray = new char[bufferSize]{};
  try
  {
    while (input)
    {
      char buffer[bufferSize] = { 0 };
      input >> std::noskipws;
      size_t i = enterBuffer(buffer, input, bufferSize);

      moveBuffer(buffer, actualArray, actualSize, bufferSize);

      size_t maxLim = std::numeric_limits< size_t >::max();
      if (actualSize > maxLim - bufferSize)
      {
        throw std::out_of_range("Error: Array size out of range");
      }
      actualSize += bufferSize;

      if (i != bufferSize)
      {
        actualArray[i + actualSize - bufferSize] = '\0';
        input >> std::skipws;
        return { actualArray, actualSize };
      }

      char* newArray = increaseArray(actualArray, actualSize, bufferSize);
      delete[] actualArray;
      actualArray = newArray;
    }
  }
  catch (...)
  {
    input >> std::skipws;
    delete[] actualArray;
    throw;
  }
  return { nullptr, 0 };
}
