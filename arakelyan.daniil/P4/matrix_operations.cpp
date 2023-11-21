#include "matrix_operations.hpp"

double arakelyan::transformToSmoothMatrix(int * matrix, double * smooth, int rows, int cols)
{
  for (int i = 0; i < rows*cols; i++)
  {
    double sum = 0.0;
    size_t count = 0;
    int row = i / cols;
    int col = i % cols;

    for (int x = -1; x <= 1; x++)
    {
      for (int y = -1; y <= 1; y++)
      {
        if (!(x == 0 && y == 0))
        {
          int newRow = row + x;
          int newCol = col + y;

          if ((newRow >= 0) && (newCol >= 0))
          {
            if ((newRow < rows) && (newCol < cols))
            {
              int index = newRow * cols + newCol;
              sum += matrix[index];
              count++;
            }
          }
        }
      }
    }

    smooth[i] = sum / count;
  }
  return *smooth;
}
