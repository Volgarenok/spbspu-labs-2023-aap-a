#include "fillMatrix.hpp"
#include <stdexcept>

void isaychev::fillMatrix(std::istream &input, int * matrix, isaychev::ulli_t rs, isaychev::ulli_t cs)
{
  for (isaychev::ulli_t i = 0; i < rs * cs; ++i)
  {
    input >> matrix[i];
    if (!input)
    {
      throw std::invalid_argument("Elements of matrix must be integer numbers");
    }
  }
}
