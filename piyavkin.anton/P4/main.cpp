#include <iostream>
#include <cstdlib>
#include <fstream>
#include "nonzero.hpp"
#include "lowertriangularmatrix.hpp"
#include "inputarray.hpp"

int main(int argc, char * argv[])
{
  using namespace piyavkin;
  if (argc != 4)
  {
    std::cerr << "Arguments entered incorrectly\n";
    return 1;
  }
  char * endOfParsing = nullptr;
  int num = std::strtoll(argv[1], &endOfParsing, 10);
  if (*endOfParsing != '\0')
  {
    std::cerr << "The first parameter is incorrectly specified\n";
    return 3;
  }
  else
  {
    try
    {
      if (num != 1 && num != 2)
      {
        std::cerr << "The first parameter is incorrectly specified\n";
        return 3;
      }
    }
    catch (...)
    {
      std::cerr << "The first parameter is incorrectly specified\n";
      return 3;
    }
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (num == 1)
    {
      int matrix[10000]{};
      for (size_t i = 0; i < rows * cols; ++i)
      {
        input >> matrix[i];
      }
      if (!input)
      {
        std::cerr << "Can not read number\n";
        return 2;
      }
      std::ofstream output(argv[3]);
      output << (LowerTriangularMatrix(rows * cols, rows, cols, matrix) && NonZero(rows * cols, matrix)) << "\n";
    }
    if (num == 2)
    {
      int * matrix = new int [rows*cols];
      size_t result = InputArray(input, matrix, rows * cols, rows * cols);
      if (!input)
      {
        std::cerr << "Can not read\n";
        delete [] matrix;
        return 2;
      }
      std::ofstream output(argv[3]);
      output << (LowerTriangularMatrix(result, rows, cols, matrix) && NonZero(result, matrix)) << "\n";
      delete [] matrix;
    }
  }
}

