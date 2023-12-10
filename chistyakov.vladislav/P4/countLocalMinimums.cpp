#include "countLocalMinimums.hpp"
#include <stdexcept>
#include <limits>
#include "min.hpp"

size_t chistyakov::countLocalMinimums(const int * array, size_t rows, size_t cols)
{
  if (rows <= 2 || cols <= 2)
  {
    return 0;
  }

  size_t result = 0;
  for (size_t idx = cols + 1; idx < (rows - 1) * cols; ++idx)
  {
    if (idx % cols != 0 && (idx + 1) % cols != 0)
    {
      int minRowUp = min(array[idx - cols - 1], array[idx - cols], array[idx - cols + 1]);
      int minRowDown = min(array[idx + cols - 1], array[idx + cols], array[idx + cols + 1]);
      if (array[idx] < min(minRowUp, minRowDown, array[idx - 1], array[idx + 1]))
      {
        size_t max_size = std::numeric_limits< size_t >::max();

        if (result == max_size)
        {
          throw std::logic_error("matrix is too long");
        }
        else
        {
          ++result;
        }
      }
    }
  }
  return result;
}
