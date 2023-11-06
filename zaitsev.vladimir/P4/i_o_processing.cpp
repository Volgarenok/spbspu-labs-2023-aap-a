#include "i_o_processing.h"

void zaitsev::readMatrix(std::ifstream& input, double* destination, size_t size)
{
  size_t counter = 0;
  for (size_t i = 0; i < size; ++i)
  {
    input >> *destination;
    ++destination;
    if (input)
    {
      ++counter;
    }
  }
  char check_size = '\0';
  input >> check_size;
  if (counter != size || input)
  {
    throw std::range_error("Input data is not desired matrix");
  }
  return;
}

std::ofstream& zaitsev::writeMatrix(std::ofstream& output, const double* destination, size_t rows, size_t cols)
{
  output << rows << " " << cols << " ";
  for (size_t i = 0; i < rows * cols; ++i)
  {
    output.precision(1);
    output << std::fixed << *destination << " ";
    ++destination;
  }
  output << '\n';
  return output;
}