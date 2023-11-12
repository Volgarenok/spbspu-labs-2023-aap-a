#include "input_array.hpp"

size_t nikitov::inputArray(std::istream& input, int matrix[], size_t rows, size_t cols)
{
  for (size_t i = 0; i != rows*cols; ++i)
  {
    input >> matrix[i];
    if (!input)
    {
      return i + 1;
    }
  }
  return 0;
}
