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
  int num = 0;
  try
  {
    if (argc != 4)
    {
      throw std::logic_error("Wrong number of elements in command line argument");
    }
    if (argv[1][1] != '\0')
    {
      throw std::logic_error("Wrong numder of task input");
    }
    try
    {
      num = std::stoll(argv[1]);
    }
    catch (...)
    {
      throw std::logic_error("Cannot parse a value");
    }
    if (num != 1 && num != 2)
    {
      throw std::logic_error("Wrong task number");
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
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

  size_t maxSize = rows * cols;
  int * pMatr = nullptr;
  int matr[10000] = {0};
  try
  {
    if (num == 1)
    {
      if (maxSize > 10000)
      {
        throw std::logic_error("Matrix is to big");
      }
      pMatr = matr;
    }
    if (num == 2)
    {
      pMatr = new int [maxSize];
    }
    for (size_t i = 0; i < maxSize; ++i)
    {
      pMatr[i] = 0;
    }
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Cannot allocate memory for matrix\n";
    return 2;
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }

  try
  {
    inputMatrix(input, pMatr, maxSize);
  }
  catch (const std::logic_error &e)
  {
    if (num == 2)
    {
      delete [] pMatr;
    }
    std::cerr << e.what() << "\n";
    return 2;
  }
  int maxMatrCol = countInMatr(pMatr, rows, cols);
  std::ofstream output(argv[3]);
  output << maxMatrCol << "\n";

  if (num == 2)
  {
    delete [] pMatr;
  }
}
