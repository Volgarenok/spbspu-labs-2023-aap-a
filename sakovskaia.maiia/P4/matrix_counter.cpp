#include "matrix.hpp"
#include <cmath>

void sakovskaia::countCounterclockwiseMatrix(int * a, size_t rows, size_t columns)
{
  int n = 0;
  size_t cnt = 0;
  size_t circle = 1;
  size_t index = 0;
  size_t cnt_columns = columns;
  for (circle = 1; circle <= (std::ceil((std::min(rows, columns)) / 2) + 1); circle += 1)
  {
    for (index = cnt * rows + cnt; index <= (rows * columns - columns * circle + cnt); index = index + rows)
    {
      a[index] = ++n;
    }
    for (index = (rows * columns - columns * circle + cnt + 1); index <= (rows * columns - columns * circle + cnt + cnt_columns - 1); ++index)
    {
      a[index] = ++n;
    }
    if (index > rows)
    {
      for (index = (rows * columns - columns * circle - circle); index > (circle * rows - circle); index = index - rows)
      {
        a[index] = ++n;
      }
    }
    if ((index < rows) || (circle != (std::ceil((std::min(rows, columns)) / 2) + 1)))
    {
      a[circle * rows - circle] = ++n;
    }
    for (index = (circle * (rows - 1) - 1); index >= (cnt * rows + circle); --index)
    {
      a[index] = ++n;
    }
    cnt += 1;
    cnt_columns = cnt_columns - 2;
  }
}

void sakovskaia::countAnswer(int * input_matrix, const int * counterclockwise_matrix, size_t size)
{
  for (size_t index = 0; index < size; ++index)
  {
    input_matrix[index] += counterclockwise_matrix[index];
  }
}
