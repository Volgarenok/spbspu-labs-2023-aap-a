#include "cnt_nzr_dig.hpp"

#include <algorithm>

size_t countOverMainDiag(const int matrix[], size_t rows, size_t cols)
{
  size_t upper_counter = 0;
  for (size_t j = 1; j < cols; ++j)
  {
    bool is_zero = false;
    size_t k = j;
    for (size_t i = 0; i < std::min(rows, cols); ++i)
    {
      if (k < cols)
      {
        if (matrix[i * cols + k] == 0)
        {
          is_zero = true;
        }
        ++k;
      }
    }
    if (is_zero == false)
    {
      ++upper_counter;
    }
  }
  return upper_counter;
}

size_t countBelowMainDiag(const int matrix[], size_t rows, size_t cols)
{
  size_t below_counter = 0;
  for (size_t i = 1; i < rows; ++i)
  {
    bool is_zero = false;
    size_t k = i;
    for (size_t j = 0; j < std::min(rows, cols); ++j)
    {
      if (k < rows)
      {
        if (matrix[k * cols + j] == 0)
        {
          is_zero = true;
        }
        ++k;
      }
    }
    if (is_zero == false)
    {
      ++below_counter;
    }
  }
  return below_counter;
}

size_t lebedev::countNotZeroDiags(const int matrix[], size_t rows, size_t cols)
{
  size_t counter = 0;
  size_t upper_counter = 0;
  size_t below_counter = 0;
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  upper_counter = countOverMainDiag(matrix, rows, cols);
  counter += upper_counter;
  below_counter = countBelowMainDiag(matrix, rows, cols);
  counter += below_counter;
  return counter;
}
