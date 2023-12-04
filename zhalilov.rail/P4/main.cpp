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
    size_t pos = 0;
    num = std::stoi(argv[1], &pos);
    if (argv[1][pos] != '\0')
    {
      throw std::invalid_argument("Incorrect arg of task number");
    }
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

  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Invalid matrix parameteres\n";
    return 2;
  }

  using namespace zhalilov;
  size_t nonZeroDiags = 0;
  int *matrix = nullptr;
  int statMatrix[10000] = {};
  if (num == 1)
  {
    matrix = statMatrix;
  }
  if (num == 2)
  {
    matrix = new int[rows * cols];
    for (size_t i = 0; i < rows * cols; i++)
    {
      matrix[i] = 0;
    }
  }
  if (!inputMatrix(matrix, rows, cols, input))
  {
    std::cerr << "Invalid matrix source\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  nonZeroDiags = countNonZeroDiags(matrix, rows, cols);
  std::ofstream output(argv[3]);
  output << nonZeroDiags << "\n";
  if (num == 2)
  {
    delete[] matrix;
  }
  return 0;
}
