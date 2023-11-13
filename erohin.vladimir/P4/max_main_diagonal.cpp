#include "max_main_diagonal.hpp"
#include <limits>
#include <stdexcept>

bool erohin::isOutSum(const long long & sum, const long long & a)
{
  long long max_size = std::numeric_limits< long long >::min();
  long long min_size = std::numeric_limits< long long >::max();
  if (a > 0)
  {
    return (sum > max_size - a);
  }
  else
  {
    return (sum > min_size + std::abs(a));
  }
}

long long erohin::maxMainDiagonal(int * matrix, const size_t & rows, const size_t & cols)
{
  if (rows < 2 && cols < 2)
  {
    throw std::logic_error("Impossible to find diagonal parallel to main");
  }
  long long sum = 0;
  long long max_sum = std::numeric_limits< long long >::min();
  for (size_t i = 1; i < rows; ++i)
  {
    sum = 0;
    for (size_t j = 0; j < std::min(rows - i, cols); ++j)
    {
      if (isOutSum(sum, matrix[rows * (i + j) + j]))
      {
        throw std::range_error("Sum is out of range");
      }
      sum += matrix[rows * (i + j) + j];
    }
    if (sum > max_sum)
    {
      max_sum = sum;
    }
  }
  for (size_t j = 1; j < cols; ++j)
  {
    sum = 0;
    for (size_t i = 0; i < std::min(cols - j, rows); ++i)
    {
      if (isOutSum(sum, matrix[rows * i + (j + i)]))
      {
        throw std::range_error("Sum is out of range");
      }
      sum += matrix[rows * i + (j + i)];
    }
    if (sum > max_sum)
    {
      max_sum = sum;
    }
  }
  return max_sum;
}
