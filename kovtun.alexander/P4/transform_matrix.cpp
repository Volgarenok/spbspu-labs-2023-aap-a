#include "transform_matrix.h"

void kovtun::transformMatrix(int * matrix, size_t rows, size_t cols)
{
  size_t top = 0;
  size_t bottom = rows - 1;
  size_t right = cols - 1;
  size_t left = 0;

  int add = 1;

  while (top <= bottom && left <= right)
  {
    for (size_t i = top; i <= bottom; i++)
    {
      matrix[i * cols + left] += add;
      add++;
    }
    left++;

    for (size_t i = left; i <= right; i++)
    {
      matrix[bottom * cols + i] += add;
      add++;
    }
    bottom--;

    for (size_t i = bottom; i + 1 >= top + 1; i--)
    {
      matrix[i * cols + right] += add;
      add++;
    }
    right--;

    for (size_t i = right; i >= left; i--)
    {
      matrix[top * cols + i] += add;
      add++;
    }
    top++;
  }

}
