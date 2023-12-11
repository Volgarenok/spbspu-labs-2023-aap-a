#include "input_output_matrix.hpp"

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
  std::ios_base::fmtflags defFlags = output.flags();
  std::streamsize defPrecision = output.precision();
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << " " << std::fixed << std::setprecision(1) << matrix[i * cols + j];
    }
  }
  output.flags(defFlags);
  output.precision(defPrecision);
  return output;
}
