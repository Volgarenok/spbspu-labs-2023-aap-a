#include "read_to_array.h"
#include "transform_matrix.h"
#include "equal_nums_counter.h"

#include <iostream>
#include <fstream>
#include <exception>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    if (argc < 4)
    {
      std::cerr << "not enough arguments\n";
    }
    else
    {
      std::cerr << "too many arguments\n";
    }

    return 1;
  }

  size_t num = 0;
  try
  {
    num = std::stoll(argv[1]);
    if (num != 1 && num != 2)
    {
      std::cerr << "the task number must be 1 or 2\n";
      return 1;
    }
  }
  catch (const std::exception & e)
  {
    std::cerr << "failed to parse the task number: " << e.what() << "\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "file not found\n";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "row or/and column number is invalid\n";
    return 2;
  }

  std::ofstream output(argv[3]);

  size_t size = rows * cols;
  if (size == 0)
  {
    output << 0 << "\n";
    return 0;
  }

  int * matrix = nullptr;
  int sArr[10000] = {0};
  int * dArr = nullptr;
  if (num == 1)
  {
    matrix = sArr;
  }
  else
  {
    dArr = new int[size]();
    matrix = dArr;
  }

  size_t hasRead = kovtun::readToArray(input, matrix, size, size);
  if (hasRead < size)
  {
    delete [] dArr;
    std::cerr << "the matrix is invalid\n";
    return 2;
  }

  output << kovtun::countEqualInColumns(matrix, rows, cols) << "\n";

  kovtun::transformMatrix(matrix, rows, cols);
  output << rows << " " << cols;
  for (size_t i = 0; i < size; i++)
  {
    output << " " << matrix[i];
  }
  output << "\n";

  delete [] dArr;

  return 0;
}
