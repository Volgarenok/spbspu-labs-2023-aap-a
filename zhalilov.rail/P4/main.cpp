#include <iostream>
#include <fstream>

int inputMatrix(int matrix[], int rows, int cols, std::ifstream &input)
{
  for (int i = 0; i < rows * cols; i++)
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

  int rows = 0;
  int cols = 0;
  if (num == 1)
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    int matrix[10000];
    if (!input)
    {
      std::cerr << "Invalid matrix parameteres\n";
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
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Invalid matrix parameteres\n";
      return 2;
    }
    int *matrix = new int[rows * cols];
    if (inputMatrix(matrix, rows, cols, input) == -1)
    {
      std::cerr << "Invalid matrix source\n";
      return 2;
    }
  }
  return 0;
}
