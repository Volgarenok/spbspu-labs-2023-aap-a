#include "makematrix.h"

void gladyshev::makeMatrix(std::istream& input, int * matrix, size_t cols, size_t rows)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> matrix[i];
    if (!input)
    {
      throw std::runtime_error("Bad input");
    }
  }
}
