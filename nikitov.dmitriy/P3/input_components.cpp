#include "input_components.hpp"

size_t nikitov::enterBuffer(char buffer[], std::istream& input, size_t bufferSize)
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

void nikitov::moveBuffer(char buffer[], char* actualArray, size_t arraySize, size_t bufferSize)
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

char* nikitov::increaseArray(char* actualArray, size_t arraySize, size_t bufferSize)
{
  char* newArray = new char[arraySize + bufferSize]{};
  for (size_t j = 0; j != arraySize; ++j)
  {
    newArray[j] = actualArray[j];
  }
  delete[] actualArray;
  return newArray;
}
