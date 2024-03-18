#include "fillMatrix.hpp"
#include <iostream>
#include <stdexcept>

namespace petuhov
{
  void fillMatrix(int *matrix, size_t rows, size_t cols, std::istream &input)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if (!(input >> matrix[i * cols + j]))
        {
          throw std::runtime_error("Error reading matrix");
        }
      }
    }
  }
}
