#ifndef INP_MATRIX_HPP 
#define INP_MATRIX_HPP
#include <fstream>
namespace ara
{
  void inputDynMatrix(std::istream & input, int * matrix, size_t el);
  void inputStatMatrix(std::istream & input, int * matrix, size_t el);
}
#endif
