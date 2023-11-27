#include "arraycheck.hpp"

size_t marishin::checkingArray(std::istream& input, int* matrix, const size_t rows, const size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(input >> matrix[i]))
    {
      return i;
    }
  }
  return rows * cols;
}

int marishin::processingMatrix(std::istream& input, int* matrix, const size_t rows, const size_t cols, int num, const char* outputFilename)
{
  if (checkingArray(input, matrix, rows, cols) == rows * cols)
  {
    transformMatrix(matrix, rows, cols);
    std::ofstream output(outputFilename);
    inputMatrix(output, matrix, rows, cols);
    if (num == 2)
    {
      delete[] matrix;
    }
    return 0;
  }
  else
  {
    if (num == 2)
    {
      delete[] matrix;
    }
    std::cerr << "The contents of the file cannot be interpreted\n";
    return 2;
  }
}
