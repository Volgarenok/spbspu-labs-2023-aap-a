#include "input_matrix.hpp"
#include <stdexcept>

void ara::inputDynMatrix(std::istream & input, int * matrix, size_t el)
{
  for (size_t i = 0; i < el; i++)
  {
    if(!(input >> matrix[i]))
    {
      delete [] matrix;
      throw std::logic_error("Cannot read matrix");
    }
  }
}

void ara::inputStatMatrix(std::istream & input, int *matrix, size_t el)
{
  for (size_t i = 0; i < el; ++i)
  {
    if(!(input >> matrix[i]))
    {
      throw std::logic_error("Cannot read matrix");
    }
  }
}
