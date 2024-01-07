#include "input_array.hpp"
#include <limits>
#include <stdexcept>
#include "input_components.hpp"

std::pair< char*, size_t > nikitov::inputArray(std::istream& input)
{
  constexpr size_t bufferSize = 25;
  size_t actualSize = 0;

  char* actualArray = new char[bufferSize]{};
  try
  {
    for (;;)
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

      actualArray = increaseArray(actualArray, actualSize, bufferSize);
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
