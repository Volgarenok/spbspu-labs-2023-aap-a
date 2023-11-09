#include <iostream>
#include <fstream>

int inputMatrix(int matrix[], int rows, int cols, std::ifstream &input)
{
  for (int i = 0; i < rows * cols, i++)
  {
    if (!(input >> matrix[i]))
    {
      return -1;
    }
  }
  return 0;
}

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  int num = 0;
  try
  {
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  if (num == 1)
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    int matrix[10000];
    if (!input)
    {
      std::cerr << "Invalid matrix arguments\n";
      return 2;
    }
    if (inputMatrix(matrix, rows, cols, input) == -1)
    {
      std::cerr << "Invalid matrix source\n";
      return 2;
    }
  }
  if (num == 2)
  {
    int *matrix = new int[rows * cols];
    if (inputMatrix(matrix, rows, cols, input) == -1)
    {
      std::cerr << "Invalid matrix source\n";
      return 2;
    }
    return 0;
  }
}


