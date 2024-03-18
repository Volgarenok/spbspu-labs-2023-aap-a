#include "input_array.hpp"

size_t lopatina::inputArray(std::istream & in, int * matrix, size_t amount, size_t toread)
{
  for (size_t i = 0; i < std::min(toread, amount); ++i)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return std::min(toread, amount);
}
