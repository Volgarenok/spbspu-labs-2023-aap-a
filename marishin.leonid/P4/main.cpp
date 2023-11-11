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
  int num = 0;
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
  int rows = 0;
  int cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "The contents of the file cannot be interpreted\n";
    return 2;
  }
  if (num == 1)
  {
    const int arraySize = 10000;
    int matrix[arraySize]{};
    if (arrayCheck(input, matrix, rows, cols, num) == 0)
    {
      matrixTransformation(matrix, rows, cols);
      std::ofstream output(argv[3]);
      matrixEntry(output, matrix, rows, cols);
    }
    else
    {
      std::cerr << "The contents of the file cannot be interpreted\n";
      return 2;
    }
  }
  else if (num == 2)
  {
    int* matrix = new int[rows * cols];
    if (arrayCheck(input, matrix, rows, cols, num) == 0)
    {
      matrixTransformation(matrix, rows, cols);
      std::ofstream output(argv[3]);
      matrixEntry(output, matrix, rows, cols);
      delete[] matrix;
    }
    else
    {
      delete[] matrix;
      std::cerr << "The contents of the file cannot be interpreted\n";
      return 2;
    }
  }
}
