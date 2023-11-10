#include "matrix_transform.hpp"
#include <sys/wait.h>

double ara::transformToSmoothMatrix(int * matrix, double * smooth, size_t rows, size_t cols)
{
  for (int i = 0; i < rows*cols; i++) {
    double sum = 0.0;
    int count = 0;
    int row = i / cols;
    int col = i % cols;

    // Перебираем соседние элементы
    for (int x = -1; x <= 1; x++)
    {
      for (int y = -1; y <= 1; y++)
      {
        if (!(x == 0 && y == 0))
        {
          int newRow = row + x;
          int newCol = col + y;

          if ((newRow >= 0) && (newCol >= 0) && ((newRow < rows) && (newCol < cols)))
          {
            int index = newRow * cols + newCol;
            sum += matrix[index];
            count++;
          }
        }
      }
    }

    smooth[i] = sum / count;
  }
  return *smooth;
}
