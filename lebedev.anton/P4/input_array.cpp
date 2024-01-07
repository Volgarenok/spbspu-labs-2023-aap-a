#include "input_array.hpp"

size_t lebedev::inputArray(std::istream & input, int matrix[], size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(input >> matrix[i]))
    {
      return i;
    }
  }
  return rows * cols;
}
