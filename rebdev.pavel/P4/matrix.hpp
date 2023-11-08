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
      matrix(int arrayMode, std::ifstream & inputFile);
      ~matrix();

      size_t localMax();

    private:
      size_t colums_, rows_;
      long long int * arrayOfElements_;
      std::ifstream inputFile_;
      
      void fillingTheMatrix();
      bool isNumberOfElementIsCorrect(size_t itemOfNumber, int columIndex, int rowIndex);
  };
}
#endif
