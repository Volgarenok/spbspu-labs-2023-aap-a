#include "matrix.hpp"
#include "matrix_input_res.hpp"
#include <math.h>

void sakovskaia::counterclockWiseMatrixCounter(int * a, size_t rows, size_t columns)
{
  int n = 0;
  size_t cnt = 0;
  size_t circle = 1;
  size_t index = 0;
  size_t cntcolumns = columns;
  for (circle = 1; circle <= (ceil((std::min(rows, columns)) / 2)); ++circle)
  {
    for (index = cnt; index <= (rows * columns - columns * circle + cnt); index = index + rows)
    {
      a[index] = ++n;
    }
    for (index = (rows * columns - columns * circle + cnt + 1); index <= (rows * columns - columns * circle + cnt + cntcolumns - 1); ++index)
    {
      a[index] = ++n;
    }
    for (index = (rows * columns - columns * circle - circle); index <= (circle * (columns - 1)); index = index - rows)
    {
      a[index] = ++n;
    }
    for (index = (circle * (columns - 1) - 1); index <= (cnt * columns + circle); --index)
    {
      a[index] = ++n;
    }
    ++cnt;
    cntcolumns = cntcolumns - 2;
  }
}

sakovskaia::answerCounter::answerCounter():
  index(0)
{}

void sakovskaia::answerCounter::operator()(int * inputmatrix, int * counterclockwisematrix, size_t size)
{
  for (index = 0; index <= size; ++index)
  {
    inputmatrix[index] += counterclockwisematrix[index];
  }
}
