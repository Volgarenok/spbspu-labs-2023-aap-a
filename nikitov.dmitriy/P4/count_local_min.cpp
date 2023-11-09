#include "count_local_min.hpp"

void nikitov::countLocalMin(size_t i, int matrix[10000], size_t cols, size_t& count)
{
  int num = matrix[i];
  if ((num < matrix[i - cols - 1] && num < matrix[i - cols] && num < matrix[i - cols + 1])
      && ( num < matrix[i - 1] && num < matrix[i + 1])
      && (num < matrix[i + cols - 1] && num < matrix[i + cols] && num < matrix[i + cols + 1]))
  {
    ++count;
  }
}
