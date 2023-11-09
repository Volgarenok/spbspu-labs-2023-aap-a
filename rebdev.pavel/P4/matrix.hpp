#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <fstream>

namespace rebdev
{
  void filling(long long int * array, long long int rows,
    long long int colums, std::ifstream & inputFile);
  long long int localMax(long long int * arr, long long int rows, long long int colums);
  bool isNumberOfElementIsCorrect(long long int itemOfNumber, long long int columIndex,
    long long int rowIndex, long long int rows, long long int colums);
}
#endif
