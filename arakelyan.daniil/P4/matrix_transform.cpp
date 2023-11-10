#include "matrix_transform.hpp"

double ara::transformToSmoothMatrix(int * matrix, double * smooth, size_t rows, size_t cols)
{
  for (int i = 0; i < rows*cols; i++) {
    double sum = 0.0;
    int count = 0;
    int row = i / cols;
    int col = i % cols;

    // Перебираем соседние элементы
    for (int x = -1; x <= 1; x++) {
      for (int y = -1; y <= 1; y++) {
        int newRow = row + x;
        int newCol = col + y;

        if ((newRow >= 0) && (newRow < rows) && (newCol >= 0 && newCol < cols)) {
          int index = newRow * cols + newCol;
          sum += matrix[index];
          count++;
        }
      }
    }

    smooth[i] = sum / count;
  }
  return *smooth;
}
