#include "input_output_matrix.hpp"
#include <cmath>
#include <stdexcept>

void arakelyan::inputMatrix(std::istream & input, int * matrix, size_t el)
{
  for (size_t i = 0; i < el; i++)
  {
    if (!(input >> matrix[i]))
    {
      throw std::logic_error("Cannot read matrix, not enough data");
    }
  }
}

std::ostream & arakelyan::outputMatrix(std::ostream & output, const double * matrix, size_t rows, size_t cols)
{
  output << rows << " " << cols;
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << " " << std::round(matrix[i * cols + j ] * 10) / 10;
    }
  }
  return output;
}
