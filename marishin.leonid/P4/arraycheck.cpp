#include "arraycheck.hpp"

int marishin::arrayCheck(std::ifstream& input, int* matrix, int rows, int cols, int num)
{
  if (num == 1)
  {
    for (int i = 0; i < rows * cols; ++i)
    {
      if (!(input >> matrix[i]))
      {
        return 1;
      }
    }
    return 0;
  }
  else
  {
    for (int i = 0; i < rows * cols; ++i)
    {
      if (!(input >> matrix[i]))
      {
        return 1;
      }
    }
    return 0;
  }
}
