#include <iostream>
#include <string>
#include <fstream>
#include "arraycheck.hpp"
#include "matrixtransformation.hpp"

int main(int argc, char* argv[])
{
  using namespace marishin;
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
  char* end = nullptr;
  int num = std::strtoll(argv[1], std::addressof(end), 10);
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "Value out of range\n";
    return 1;
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "The contents of the file cannot be interpreted\n";
    return 2;
  }
  int* matrix = nullptr;
  if (num == 1)
  {
    const size_t arraySize = 10000;
    int matrix[arraySize]{};
  }
  else if (num == 2)
  {
    int* matrix = new int[rows * cols];
  }
  if (checkingArray(input, matrix, rows, cols) == rows * cols)
  {
    transformMatrix(matrix, rows, cols);
    std::ofstream output(argv[3]);
    inputMatrix(output, matrix, rows, cols);
    if (num == 2)
    {
      delete[] matrix;
    }
  }
  else
  {
    if (num == 2)
    {
      delete[] matrix;
    }
    std::cerr << "The contents of the file cannot be interpreted\n";
    return 2;
  }
}
