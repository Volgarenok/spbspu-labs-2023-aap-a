#include <iostream>
#include <fstream>

#include "inputMatrix.hpp"
#include "countNonZeroDiags.hpp"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect number of arguments\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoi(argv[1]);
  }
  catch (const std::exception &e)
  {
    std::cerr << "Invalid argument of task number\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "Invalid first argument\n";
    return 1;
  }

  int rows = 0;
  int cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Invalid matrix parameteres\n";
    return 2;
  }

  using namespace zhalilov;
  int nonZeroDiags = 0;
  if (num == 1)
  {
    int matrix[10000];
    if (inputMatrix(matrix, rows, cols, input) == -1)
    {
      std::cerr << "Invalid matrix source\n";
      return 2;
    }
    
    nonZeroDiags = countNonZeroDiags(matrix, rows, cols);
  }
  if (num == 2)
  {
    int *matrix = new int[rows * cols];
    if (inputMatrix(matrix, rows, cols, input) == -1)
    {
      std::cerr << "Invalid matrix source\n";
      return 2;
    }

    nonZeroDiags = countNonZeroDiags(matrix, rows, cols);
  }

  {
    std::ofstream output(argv[3]);
    output << nonZeroDiags << "\n";
}
  return 0;
}
