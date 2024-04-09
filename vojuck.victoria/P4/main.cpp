#include <iostream>
#include <fstream>
#include <cstdlib>
#include "isUpperTriangular.hpp"
#include "findMaxSum.hpp"
#include "inputMatrix.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "there should be 3 args: a number of task, name of file to read and name of file to fill";
    return 1;
  }

  int num = 0;

  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 3;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 3;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "Invalid argument for a number of task\n";
    return 2;
  }

  std::ifstream input(argv[2]);
  size_t rows = 0, cols = 0 ;
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read!\n";
    return 2;
  }

  std::ofstream output(argv[3]);

  if (rows == 0 || cols == 0 || rows == 1 || cols == 1)
  {
    output << 0;
    return 0;
  }
  if (rows != cols)
  {
    std::cerr << "The number of rows should be equal to cols\n";
    return 2;
  }

  long long  int fixedMatrix[10000] = {0};
  long long int * matrix = nullptr;

  if (num == 1)
  {
    matrix = fixedMatrix;
  }

  else if (num == 2)
  {
    matrix = new long long int [rows * cols];
  }

  try
  {
    size_t result = vojuck::inputArray(input, matrix, rows*cols, rows*cols);
    if (result == rows*cols)
    {
      int maxSum = vojuck::findMaxSum(matrix, rows, cols);
      output << maxSum << "\n";
      output << vojuck::isUpperTriangular(matrix, rows, cols);
    }
    else
    {
      std::cerr << "Not enough data for matrix!\n";
      if (num == 2)
      {
        delete[] matrix;
      }
      return 2;
    }
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Not enough memory\n";
    delete[] matrix;
    return 3;
  }
  catch (...)
  {
    std::cerr << "Something went wrong\n";
    delete[] matrix;
    return 1;
  }
  if (num == 2)
  {
    delete[] matrix;
  }
}


