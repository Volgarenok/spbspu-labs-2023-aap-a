#ifndef MAKESTATICMATRIX_H
#define MAKESTATICMATRIX_H

#include <cstddef>
#include <fstream>
#include <stdexcept>

namespace gladyshev
{
  int goStaticMatrix(std::fstream & input, int matrix[100][100], size_t & rows, size_t & cols);
}

#endif
