#ifndef MATRIX_PROCESSING_H
#define MATRIX_PROCESSING_H

namespace zaitsev
{
  double smoothMatrixElement(const double* matrix, size_t n_rows, size_t n_cols, size_t row_pos, size_t col_pos);
  void smoothMatrix(const double* matrix, double* smoothed_matrix, size_t rows, size_t cols);
}
#endif
