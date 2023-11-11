#ifndef MATRIX_TRANSFORMATION_HPP
#define MATRIX_TRANSFORMATION_HPP
#include <fstream>
namespace marishin
{
  void matrixTransformation(int* matrix, int rows, int cols);
  void matrixEntry(std::ofstream& b, int* matrix, int rows, int cols);
}
#endif
