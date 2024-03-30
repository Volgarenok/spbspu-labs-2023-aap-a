#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "input_array.hpp"
#include "is_lowertri_matrix.hpp"
#include "count_diag_nzero.hpp"

int main(int argc, char ** argv)
{
  using namespace lopatina;
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read rows or cols\n";
    return 2;
  }

  int res1 = 0;
  size_t res2 = 0;
  int matrix_fix[10000] = {};
  int * matrix = nullptr;
  if (num == 1)
  {
    matrix = matrix_fix;
  }
  else if (num == 2)
  {
    matrix = new int[rows * cols];
  }
  size_t result = inputArray(input, matrix, rows * cols, rows * cols);
  if (result != rows * cols)
  {
    std::cerr << "Invalid input array\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  res1 = isLowerTriMatrix(matrix, rows, cols);
  res2 = countDiagWithoutZero(matrix, rows, cols);
  if (num == 2)
  {
    delete[] matrix;
  }

  std::ofstream output(argv[3]);
  if (res1 == 0)
  {
    output << "LWR-TRI-MTRX: " << "false\n" << "CNT-NZR-DIG: " << res2 << '\n';
  }
  else if (res1 == 1)
  {
     output << "LWR-TRI-MTRX: " << "true\n" << "CNT-NZR-DIG: " << res2 << '\n';
  }
  return 0;
}
