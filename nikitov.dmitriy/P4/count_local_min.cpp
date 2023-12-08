#include "count_local_min.hpp"
#include "is_min.hpp"

size_t nikitov::countLocalMin(const int matrix[], size_t rows, size_t cols)
{
  size_t position = 0;
  size_t count = 0;
  if (rows != 0 && cols != 0)
  {
    for (size_t i = 1; i != rows - 1; ++i)
    {
      position = cols * i + 1;
      for (size_t j = 1; j != cols - 1; ++j)
      {
        if (isMin(position, matrix, cols))
        {
          ++count;
        }
        ++position;
      }
    }
  }
  return count;
}

