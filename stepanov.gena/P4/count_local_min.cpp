#include "count_local_min.hpp"

size_t stepanov::countLocalMin(int const matrix[], size_t rows, size_t cols)
{
  size_t count = 0;
  if (rows != 0 && cols != 0)
  {
    for (size_t i = 1; i < rows - 1; ++i)
    {
      for (size_t j = 1; j < cols - 1; ++j)
      {
        size_t index = i * cols + j;
        if (matrix[index] < matrix[index - cols] &&
          matrix[index] < matrix[index + cols] &&
          matrix[index] < matrix[index - 1] &&
          matrix[index] < matrix[index + 1] &&
          matrix[index] < matrix[index - cols - 1] &&
          matrix[index] < matrix[index - cols + 1] &&
          matrix[index] < matrix[index + cols - 1] &&
          matrix[index] < matrix[index + cols + 1])
        {
          count++;
        }
      }
    }
  }

  return count;
}
