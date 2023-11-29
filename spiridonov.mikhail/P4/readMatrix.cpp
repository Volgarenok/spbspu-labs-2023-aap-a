#include "minSumMdg.hpp"
#include <fstream>

void spiridonov::readMatrix(std::ifstream& input, int * matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; i++)
  {
    if (!(input >> matrix[i]))
    {
      throw std::length_error("Error read matrix elements");
    }
  }
}
