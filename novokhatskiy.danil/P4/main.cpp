#include <iostream>
#include <fstream>
#include <string>
#include "searchMax.hpp"
#include "inputfile.hpp"

int main(int argc, char * argv[])
{
  using namespace novokhatskiy;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch(...)
  {
    std::cerr << "Can not parse a valut\n";
    return 2;
  }
  if ((num < 1) || (num > 2))
  {
    std::cerr << "Incorret input the first argiment";
    return 1;
  }
  int rows = 0;
  int cols = 0;
  int result = 0;
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "The file can not be read\n";
    return 2;
  }
  if (num == 1)
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    int matrix[10000];
    if (inputfile(input, matrix, rows, cols, num))
    {
      result = searchMax(matrix, rows, cols);
    }
    else
    {
      std::cerr << "Invalid matrix arguments\n";
      return 2;
    }
  }
  else if (num == 2)
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    int *matrix = new int[rows * cols];
    if (inputfile(input, matrix, rows, cols, num))
    {
      result = searchMax(matrix, rows, cols);
      delete[] matrix;
    }
    else
    {
      std::cerr << "Incorrect matrix\n";
      delete[] matrix;
      return 2;
    }
  }
  {
    std::ofstream output(argv[3]);
    output << result << "\n";
  }
  return 0;
}


