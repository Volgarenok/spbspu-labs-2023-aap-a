#include <iostream>
#include <fstream>
#include <algorithm>

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

int countNonZeroDiags(int matrix[], int rows, int cols)
{
  int count = 0;
  int sqrLength = std::min(rows, cols);
  int lineLength = sqrLength * sqrLength;
  bool isUpperZero = false;
  bool isLowerZero = false;
  for (int i = 1; i < sqrLength; i++)
  {
    for (int j = 0; j < sqrLength - i; j++)
    {
      int upperIndex = i + (cols + 1) * j;
      if (matrix[upperIndex] == 0)
      {
        isUpperZero = true;
      }
      
      int lowerIndex = lineLength - 1 - i - (cols + 1) * j;
      if (matrix[lowerIndex] == 0)
      {
        isLowerZero = true;
      }

      if (isLowerZero && isUpperZero)
      {
        break;
      }
    }
    
    count+= !isLowerZero + !isUpperZero;
    isUpperZero = false;
    isLowerZero = false;
  }
  return count;
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
    output << nonZeroDiags;
  }
  return 0;
}
