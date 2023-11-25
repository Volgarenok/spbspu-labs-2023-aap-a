#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include "inputMatrix.hpp"
#include "countIn.hpp"

int main(int argc, char ** argv)
{
  using namespace grechishnikov;
  if (argc != 4)
  {
    std::cerr << "Wrong number of elements in command line arguments\n";
    return 1;
  }
  if (std::strlen(argv[1]) != 1)
  {
    std::cerr << "Wrong numder of task input\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (...)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "Wrong task number\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a size of matrix\n";
    return 2;
  }

  size_t maxNumCol = 0;
  if (num == 1)
  {
    size_t maxSize = rows * cols;
    if (maxSize > 10000)
    {
      std::cerr << "Matrix is too big\n0";
      return 2;
    }
    int matr[10000] = {0};
    try
    {
      inputMatrix(input, matr, maxSize);
    }
    catch (const std::logic_error &e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    maxNumCol = countInMatr(matr, rows, cols);
  }
  if (num == 2)
  {
    size_t maxSize = rows * cols;
    int * matr = nullptr;
    try
    {
      matr = new int [maxSize];
      for (size_t i = 0; i < maxSize; ++i)
      {
        matr[i] = 0;
      }
      inputMatrix(input, matr, maxSize);
    }
    catch (const std::bad_alloc &e)
    {
      delete [] matr;
      std::cerr << "Cannot allocate memory for matrix\n";
      return 2;
    }
    catch (const std::logic_error &e)
    {
      delete [] matr;
      std::cerr << e.what() << "\n";
      return 2;
    }
    maxNumCol = countInMatr(matr, rows, cols);
    delete [] matr;
  }

  std::ofstream output(argv[3]);
  if (rows == 0 || cols == 0)
  {
    output << 0 << "\n";
    return 0;
  }
  output << maxNumCol << "\n";
}
