#include "makematrix.h"

int gladyshev::makeMatrix(std::fstream& input, int * matrix, size_t cols, size_t rows)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!input.eof())
    {
      if (!input)
      {
        return 2;
      }
    }
    else
    {
      return 4;
    }
    input >> matrix[i];
  }
  return 3;
}
