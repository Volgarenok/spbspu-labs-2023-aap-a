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
  char* endOfParsing = nullptr;
  try
  {
    num = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
  }
  catch (...)
  {
    std::cerr << "Can not parse a value\n";
    return 2;
  }
  if (*endOfParsing != '\0')
  {
    std::cerr << "The first argument is incorrect\n";
    return 1;
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
  int* matrix = nullptr;
  int arr[10000] = {};
  if (num == 1)
  {
    matrix = arr;
  }
  else if (num == 2)
  {
    try
    {
      matrix = new int [rows * cols];
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Not enough memory!\n";
      return 3;
    }
  }
  size_t check = inputArr(input, matrix, rows, cols);
  if (check != rows * cols)
  {
    std::cerr << "Invalid matrix\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  result = searchMax(matrix, rows, cols);
  if (num == 2)
  {
    delete[] matrix;
  }

  std::ofstream output(argv[3]);
  output << result << "\n";

  return 0;
}


