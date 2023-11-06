#include "matrix_processing.h"

double zaitsev::smoothMatrixElement(const double* matrix, size_t n_rows, size_t n_cols, size_t row_pos, size_t col_pos)
{
  double res = 0;
  double divider = (3 - (row_pos == 0 || row_pos == n_rows - 1)) * (3 - (col_pos == 0 || col_pos == n_cols - 1)) - 1;
  for (size_t i = (row_pos > 0 ? row_pos - 1 : 0); i <= (row_pos < n_rows - 1 ? row_pos + 1 : row_pos); ++i)
  {
    for (size_t j = (col_pos > 0 ? col_pos - 1 : 0); j <= (col_pos < n_cols - 1 ? col_pos + 1 : col_pos); ++j)
    {
      if (i != row_pos || j != col_pos)
      {
        res += matrix[i * n_cols + j] / divider;
      }
    }
  }
  return res;
}

void zaitsev::smoothMatrix(const double* matrix, double* smoothed_matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      smoothed_matrix[i * cols + j] = zaitsev::smoothMatrixElement(matrix, rows, cols, i, j);
    }
  }
  return;
}
