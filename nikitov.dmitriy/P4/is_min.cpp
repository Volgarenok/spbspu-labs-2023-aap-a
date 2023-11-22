#include "is_min.hpp"

bool nikitov::isMin(size_t i, const int matrix[], size_t cols)
{
  int num = matrix[i];
  if (!(num < matrix[i - cols - 1]))
  {
    return false;
  }
  if (!(num < matrix[i - cols]))
  {
    return false;
  }
  if (!(num < matrix[i - cols + 1]))
  {
    return false;
  }
  if (!(num < matrix[i - 1]))
  {
    return false;
  }
  if (!(num < matrix[i + 1]))
  {
    return false;
  }
  if (!(num < matrix[i + cols - 1]))
  {
    return false;
  }
  if (!(num < matrix[i + cols]))
  {
    return false;
  }
  if (!(num < matrix[i + cols + 1]))
  {
    return false;
  }

  return true;
}
