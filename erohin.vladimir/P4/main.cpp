#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include "fill_circle.hpp"
#include "read_print_matrix.hpp"
#include "max_main_diagonal.hpp"

int main(int argc, char * argv[])
{
  using namespace erohin;
  if (argc != 4)
  {
    std::cerr << "Wrong number of line arguments\n";
    return 1;
  }
  long long num = std::strtoll(argv[1], nullptr, 10);
  if (num == 0 || num > 2)
  {
    std::cerr << "Wrong task number\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
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
  maxSumDiagonal = findMaxMainDiagonal(matrix, rows, cols);
  try
  {
    fillCircle(matrix, rows, cols);
  }
  catch (const std::exception & e)
  {
    delete[] matrix;
    std::cerr << e.what() << "\n";
    return 4;
  }
  std::ofstream output(argv[3]);
  output << rows << " " << cols << " ";
  printMatrix(output, matrix, rows, cols);
  output << "\n";
  output << maxSumDiagonal;
  output.close();
  if (num == 2)
  {
    delete[] matrix;
  }
  return 0;
}
