#include "ioprocessing.hpp"
#include <fstream>
#include <stdexcept>

void shabalin::matrixInput(std::istream &input, int *matrix, size_t countOfElements)
{
  for (size_t i = 0; i < countOfElements; ++i)
  {
    if (!(input >> matrix[i]))
    {
      throw std::logic_error("Can't input the matrix");
    }
  }
}

void shabalin::matrixOutput(std::ostream &output, const double *matrix, size_t rows, size_t cols)
{
  if (!(output << rows << ' ' << cols))
  {
    throw std::logic_error("Can't output the result");
  }
  output << std::fixed;
  output.precision(1);
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(output << ' ' << matrix[i]))
    {
      throw std::logic_error("Can't output the result");
    }
  }
}
