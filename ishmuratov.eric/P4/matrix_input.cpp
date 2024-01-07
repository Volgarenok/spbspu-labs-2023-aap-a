#include "matrix_input.hpp"

void ishmuratov::matrixInput(std::istream& input, int * matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> matrix[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid matrix element!");
    }
  }
}
