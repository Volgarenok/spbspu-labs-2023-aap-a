#include "input_output_matrix.hpp"
#include <fstream>
#include <stdexcept>

void arakelyan::inputMatrix(std::ifstream & input, int * matrix, size_t el)
{
  for (size_t i = 0; i < el; i++)
  {
    if (!(input >> matrix[i]))
    {
      throw std::logic_error("Cannot read matrix, not enough data");
    }
  }
}
std::ofstream & arakelyan::outputTransformMatrix(std::ofstream &output, double * smoothed, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << std::fixed << std::setprecision(1) << " " << smoothed[i * cols + j];
    }
  }
  return output;
}
