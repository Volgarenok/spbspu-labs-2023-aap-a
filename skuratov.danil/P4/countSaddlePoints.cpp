#include "countSaddlePoints.h"

#include <cstddef>

size_t skuratov::countSaddlePoints(const int* array, size_t rows, size_t cols)
{
  size_t saddleCount = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      int currentElement = array[i * cols + j];
      bool isSaddle = true;
      for (size_t k = 0; k < cols; ++k)
      {
        if (currentElement > array[i * cols + k])
        {
          isSaddle = false;
          break;
        }
      }
      for (size_t k = 0; k < rows; ++k)
      {
        if (currentElement < array[k * cols + j])
        {
          isSaddle = false;
          break;
        }
      }
      if (isSaddle)
      {
        saddleCount++;
      }
    }
  }
  return saddleCount;
}
