#include "fillMatrix.hpp"

void isaychev::fillMatrix(std::ifstream &input, int * matrix, size_t rs, size_t cs)
{
  for (size_t i = 0; i < rs * cs; ++i)
  {
    input >> matrix[i];
    if (!input)
    {
      throw std::invalid_argument("Elements of matrix must be integer numbers");
    }
  }
}
