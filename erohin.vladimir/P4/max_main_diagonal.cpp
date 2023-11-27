#include "max_main_diagonal.hpp"
#include <limits>

long long erohin::maxMainDiagonal(int * matrix, const size_t & rows, const size_t & cols)
{
  long long cur_sum = 0;
  long long max_sum = std::numeric_limits< long long >::min();
  size_t cur_row = 0;
  size_t cur_col = 0;
  for (size_t i = 0; i < rows + cols - 2; ++i)
  {
    cur_sum = 0;
    if (i < rows - 1)
    {
      cur_row = i + 1;
      cur_col = 0;
    }
    else
    {
      cur_row = 0;
      cur_col = i + 2 - rows;
    }
    while (cur_row < rows && cur_col < cols)
    {
      cur_sum += matrix[(cur_row++) * rows + (cur_col++)];
    }
    if (cur_sum > max_sum)
    {
      max_sum = cur_sum;
    }
  }
  return max_sum;
}
