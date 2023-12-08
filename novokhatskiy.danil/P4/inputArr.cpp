#include "inputArr.hpp"

size_t novokhatskiy::inputArr(std::istream& input, int matrix[], size_t rows, size_t cols)
{
  for(size_t i = 0; i != rows * cols; ++i)
  {
    input >> matrix[i];
    if (!input)
    {
      return i;
    }
  }
  return rows * cols;
}
