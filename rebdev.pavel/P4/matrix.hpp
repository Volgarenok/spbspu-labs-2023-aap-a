#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <fstream>

namespace rebdev
{
  class matrix
  {
    public:
      matrix();
      matrix(size_t rows, size_t colums);

      void filling(std::ifstream & inputFile, long long int * arr);
      size_t localMax(long long int * arr);

    private:
      size_t rows_, colums_;

      bool isNumberOfElementIsCorrect(size_t itemOfNumber, int columIndex, int rowIndex);
  };
}
#endif
