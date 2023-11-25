#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "searchMax.hpp"
#include "inputArr.hpp"

int main(int argc, char * argv[])
{
  using namespace novokhatskiy;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  int num = 0;
  if (strlen(argv[1]) != 1)
  {
    std::cerr << "The first argument is wrong\n";
    return 3;
  }
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (...)
  {
    std::cerr << "Can not parse a valut\n";
    return 2;
  }
  if ((num < 1) || (num > 2))
  {
    std::cerr << "Incorrect input the first argument\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  int result = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "The file can not be read\n";
    return 2;
  }
  if ((rows != 0) && (cols != 0))
  {
    if (num == 1)
    {
      int matrix[10000] = {};
      size_t check = inputArr(input, matrix, rows, cols);
      if (check != rows * cols)
      {
        std::cerr << "Invalid matrix\n";
        return 2;
      }
      else
      {
        result = searchMax(matrix, rows, cols);
      }
    }
    else if (num == 2)
    {
      int *matrix = new int[rows * cols];
      size_t check = inputArr(input, matrix, rows, cols);
      try
      {
        matrix;
      }
      catch (const std::bad_alloc&)
      {
        std::cerr << "Not enough memory!\n";
        return 3;
      }
      if (check != rows * cols)
      {
        std::cerr << "Incorrect matrix\n";
        return 2;
        delete[] matrix;
      }
      else
      {
        result = searchMax(matrix, rows, cols);
        delete[] matrix;
      }
    }
  }

  std::ofstream output(argv[3]);
  output << result << "\n";

  return 0;
}


