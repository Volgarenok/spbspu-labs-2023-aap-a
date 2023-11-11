#include "arraycheck.hpp"

bool marishin::arrayCheck(std::istream& n, int* matrix, size_t rows, size_t cols)
{
  for (int i = 0; i < rows * cols; ++i)
  {
    if (!(n >> matrix[i]))
    {
      return false;
    }
    return true;
  }
}
