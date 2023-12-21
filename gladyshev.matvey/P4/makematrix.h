#ifndef MAKEMATRIX_H
#define MAKEMATRIX_H

#include <fstream>
#include <cstddef>

namespace gladyshev
{
 void makeMatrix(std::istream& input, int * matrix, size_t cols, size_t rows);
}

#endif
