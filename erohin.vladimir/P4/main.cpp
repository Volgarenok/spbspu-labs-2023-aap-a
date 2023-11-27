#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include "circle_fill.hpp"
#include "read_print_matrix.hpp"
#include "max_main_diagonal.hpp"
#include "is_numeric.hpp"

int main(int argc, char * argv[])
{
  using namespace erohin;
  if (argc != 4)
  {
    std::cerr << "Wrong number of line arguments\n";
    return 1;
  }
  int num = 0;
  if (!isNumeric(argv[1]))
  {
    std::cerr << "Value of first CLA is not a number\n";
    return 1;
  }
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  if (num > 2)
  {
    std::cerr << "Wrong task number\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  bool isExist = true;
  long long maxSumDiagonal = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number of rows and columns\n";
    return 2;
  }
  int * matrix = nullptr;
  int * dynamic_matrix =  nullptr;
  int static_matrix[10000] = {0};
  if (num == 1)
  {
    matrix = static_matrix;
  }
  else if (num == 2)
  {

    try
    {
      dynamic_matrix = new int[rows * cols];
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Error of allocation memory in free store\n";
      return 3;
    }
    matrix = dynamic_matrix;
  }
  readMatrix(input, matrix, rows, cols);
  if (!input)
  {
    std::cerr << "Invalid value of matrix element\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  input.close();
  if (rows < 2 && cols < 2)
  {
    isExist = false;
  }
  else
  {
    maxSumDiagonal = maxMainDiagonal(matrix, rows, cols);
  }
  try
  {
    circleFill(matrix, rows, cols);
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 4;
  }
  std::ofstream output(argv[3]);
  output << rows << " " << cols;
  printMatrix(output, matrix, rows, cols);
  output << "\n";
  if (isExist)
  {
    output << maxSumDiagonal;
  }
  output.close();
  if (num == 2)
  {
    delete[] matrix;
  }
  return 0;
}
