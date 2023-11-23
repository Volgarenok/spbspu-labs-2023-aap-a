#include <iostream>

#include "matrixchecktri.h"
#include "zeromatrix.h"
#include "makematrix.h"

int main(int argc, char * argv[])
{
  using namespace gladyshev;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  unsigned short int ex_num = 0;
  try
  {
    ex_num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  if (ex_num != 2 && ex_num != 1)
  {
    std::cerr << "No such number of task\n";
    return 1;
  }
  size_t rows = 0, cols = 0;
  std::fstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }
  if (rows < 1 || cols < 1)
  {
    return 0;
  }
  if (rows != cols)
  {
    std::cerr << "Matrix is not a square\n";
    return 1;
  }
  if (rows == 1 && cols == 1)
  {
    std::cout << "So small matrix\n";
    return 1;
  }
  std::fstream output(argv[3], std::ios::out);
  if (ex_num == 1)
  {
    int matrix[10000] {};
    try
    {
      makeMatrix(input, matrix, rows, cols);
    }
    catch (const std::runtime_error & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
    if (isUpperTriangular(matrix, rows, cols) && !isZeroMatrix(matrix, rows, cols))
    {
      output << "True\n";
    }
    else
    {
      output << "False\n";
    }
  }
  else
  {
    int * matrix = nullptr;
    try
    {
      matrix = new int [rows * cols];
      makeMatrix(input, matrix, rows, cols);
    }
    catch (const std::runtime_error & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      delete[] matrix;
      return 2;
    }
    if (isUpperTriangular(matrix, rows, cols) && !isZeroMatrix(matrix, rows, cols))
    {
      output << "True\n";
    }
    else
    {
      output << "False\n";
    }
    delete[] matrix;
  }
  return 0;
}
