#include "zeromatrix.h"

bool gladyshev::isZeroMatrix(int ** matrix, size_t rows, size_t cols)
{
  size_t counter = 0;
  size_t maxsize = std::numeric_limits< size_t >::max();
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (matrix[i][j] == 0)
      {
        if (counter == maxsize)
        {
          throw std::logic_error("Is too big");
        }
      counter += 1;
      }
    }
  }
  if (counter == rows * cols)
  {
    return true;
  }
  return false;
}

bool gladyshev::isZeroMatrix(int matrix[100][100], size_t rows)
{
  size_t counter = 0;
  size_t maxsize = std::numeric_limits< size_t >::max();
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < rows; ++j)
    {
      if (matrix[i][j] == 0)
      {
        if (counter == maxsize)
        {
          throw std::logic_error("Is too big");
        }
      counter += 1;
      }
    }
  }
  if (counter == rows * rows)
  {
    return true;
  }
  return false;
}
