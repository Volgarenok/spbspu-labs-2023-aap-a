#include "count_local_min.hpp"
#include "is_min.hpp"

void nikitov::countLocalMin(size_t i, const int matrix[], size_t cols, size_t& count)
{
  if (isMin(i, matrix, cols))
  {
    ++count;
  }
}
