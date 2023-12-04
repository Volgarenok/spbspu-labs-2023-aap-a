#include <iostream>
#include <cstdlib>
#include <fstream>
#include "checknonzero.hpp"
#include "checklowertriangularmatrix.hpp"
#include "inputarray.hpp"

int main(int argc, char * argv[])
{
  using namespace piyavkin;
  if (argc != 4)
  {
    std::cerr << "Arguments entered incorrectly\n";
    return 1;
  }
  int num = 0;
  try
  {
    char * endOfParsing = nullptr;
    num = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
    if (*endOfParsing != '\0')
    {
      throw std::exception();
    }
    if (num != 1 && num != 2)
    {
      throw std::exception();
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
  int * matrix = nullptr;
  int a[10000]{};
  if (num == 1)
  {
    matrix = a;
  }
  if (num == 2)
  {
    try
    {
      matrix = new int [rows * cols]{};
    }
    catch (...)
    {
      std::cerr << "Dynamic memory overflow";
      return 3;
    }
  }
  size_t result = inputArray(input, matrix, rows * cols, rows * cols);
  if (!input)
  {
    if (num == 2)
    {
      delete [] matrix;
    }
    std::cerr << "Can not read number\n";
    return 2;
  }
  std::ofstream output(argv[3]);
  output << (checkLowerTriangularMatrix(result, rows, cols, matrix) && checkNonZero(rows * cols, matrix)) << "\n";
  if (num == 2)
  {
    delete [] matrix;
  }
}
