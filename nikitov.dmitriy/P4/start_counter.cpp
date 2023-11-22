#include "start_counter.hpp"
#include "count_local_min.hpp"

void nikitov::startCounter(const int matrix[], size_t rows, size_t cols, size_t& count)
{
  size_t position = 0;
  if (rows != 0 && cols != 0)
  {
    for (size_t i = 1; i != rows - 1; ++i)
    {
      position = cols * i + 1;
      for (size_t j = 1; j != cols - 1; ++j)
      {
        countLocalMin(position, matrix, cols, count);
        ++position;
      }
    }
  }
}

