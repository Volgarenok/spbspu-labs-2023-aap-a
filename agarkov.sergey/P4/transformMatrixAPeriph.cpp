#include "transformMatrixAPeriph.hpp"
#include <algorithm>

void agarkov::transformMatrixAPeriph(int* array, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      array[i * cols + j] += std::min({i + 1, j + 1, rows - i, cols - j});
    }
  }
}

