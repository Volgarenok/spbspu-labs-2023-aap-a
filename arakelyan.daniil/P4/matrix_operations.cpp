#include "matrix_operations.hpp"

void arakelyan::smoothedMatrixCreation(const int * matrix, double * smooth, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows*cols; i++)
  {
    double sum = 0.0;
    size_t count = 0;
    size_t row = i / cols;
    size_t col = i % cols;

    for (int x = -1; x <= 1; x++)
    {
      for (int y = -1; y <= 1; y++)
      {
        if (!(x == 0 && y == 0))
        {
          size_t newRow = row + x;
          size_t newCol = col + y;

          if ((newRow < rows) && (newCol < cols))
          {
            size_t index = newRow * cols + newCol;
            sum += matrix[index];
            count++;
          }
        }
      }
    }
    smooth[i] = sum / count;
  }
}
