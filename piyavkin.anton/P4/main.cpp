#include <iostream>
#include <cstdlib>
#include <fstream>
#include "nonzero.hpp"
#include "downtrimatrix.hpp"
#include "inputarray.hpp"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Arguments entered incorrectly\n";
    return 1;
  }
  try
  {
    int num = std::stoll(argv[1]);
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
  int num = std::stoll(argv[1]);
  if (num == 1)
  {
    int rows = 0;
    int cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    int matrix[10000];
    for (int i = 0; i < rows * cols; ++i)
    {
      input >> matrix[i];
    }
    if (!input)
    {
      std::cerr << "Can not read number\n";
      return 2;
    }
    std::ofstream output(argv[3]);
    output << DownTriMatrix(rows * cols, rows, cols, matrix) * NonZero(rows * cols, matrix) << "\n";
  }
  if (num == 2)
  {
    int rows = 0;
    int cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    int * matrix = new int [rows*cols];
    size_t result = InputArray(input, matrix, rows * cols, rows * cols);
    if (!input)
    {
      std::cerr << "Can not read\n";
      delete [] matrix;
      return 2;
    }
    std::ofstream output(argv[3]);
    output << DownTriMatrix(result, rows, cols, matrix) * NonZero(result, matrix) << "\n";
    delete [] matrix;
  }
}
