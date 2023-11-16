#include "input_output_matrix.hpp"
#include <fstream>
#include <stdexcept>

void ara::inputDynMatrix(std::ifstream & input, int * matrix, size_t el)
{
  for (size_t i = 0; i < el; i++)
  {
    if(!(input >> matrix[i]))
    {
      throw std::logic_error("Cannot read matrix, not enough data");
    }
  }
}

void ara::inputStatMatrix(std::ifstream & input, int * matrix, size_t el)
{
  for (size_t i = 0; i < el; ++i)
  {
    if(!(input >> matrix[i]))
    {
      throw std::logic_error("Cannot read matrix");
    }
  }
}

std::ofstream & ara::outputTransformMatrix(std::ofstream &output, double * smoothed, int rows, int cols)
{
  output << "Transformed matrix:\n";
  for (int i = 0; i < rows; ++i)
  {
    output << "|";
    for(int j = 0; j < cols; ++j)
    {
      output << std::fixed << std::setprecision(1) << " " <<
        smoothed[i * cols + j];
    }
    output << " |\n";
  }
  return output;
}
