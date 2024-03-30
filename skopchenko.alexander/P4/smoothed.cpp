#include "smoothed.h"
#include <cmath>

void skopchenko::makeSmoothMatrix(const int *matrix, double *smoothMatrix, const size_t rows, const size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      size_t count = 0;
      double sum = 0;
      if (rows == 1 && cols == 1)
      {
        return;
      }
      if (i > 0)
      {
        sum += matrix[(i - 1) * cols + j];
        count++;
      }
      if (i < rows - 1)
      {
        sum += matrix[(i + 1) * cols + j];
        count++;
      }
      if (j > 0)
      {
        sum += matrix[i * cols + (j - 1)];
        count++;
      }
      if (j < cols - 1)
      {
        sum += matrix[i * cols + (j + 1)];
        count++;
      }
      if (i > 0 && j > 0)
      {
        sum += matrix[(i - 1) * cols + (j - 1)];
        count++;
      }
      if (i > 0 && j < cols - 1)
      {
        sum += matrix[(i - 1) * cols + (j + 1)];
        count++;
      }
      if (i < rows - 1 && j > 0)
      {
        sum += matrix[(i + 1) * cols + (j - 1)];
        count++;
      }
      if (i < rows - 1 && j < cols - 1)
      {
        sum += matrix[(i + 1) * cols + (j + 1)];
        count++;
      }
      smoothMatrix[i * cols + j] = sum / count;
    }
  }
}
