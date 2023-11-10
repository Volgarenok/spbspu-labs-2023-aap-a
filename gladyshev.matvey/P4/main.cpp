#include <iostream>

#include "makedynamicmatrix.h"
#include "matrixcheck.h"
#include "zeromatrix.h"
#include "makestaticmatrix.h"

int main(int argc, char * argv[])
{
  using namespace gladyshev;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  unsigned short int ex_num = 0;
  try
  {
    ex_num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  if (ex_num != 2 and ex_num != 1)
  {
    std::cerr << "No such number of task\n";
    return 1;
  }
  size_t rows = 0, cols = 0;
  std::fstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }
  if (rows < 1 or cols < 1)
  {
    return 0;
  }
  if (rows != cols)
  {
    std::cerr << "Matrix is not a square\n";
    return 1;
  }
  std::fstream output(argv[3], std::ios::out);
  if (ex_num == 1)
  {
    int array[100][100] {};
    if (goStaticMatrix(input, array, rows, cols) == 4)
    {
      std::cerr << "Lack of data\n";
      return 2;
    }
    try
    {
      if ((rows * cols) > 1)
      {
        if (isUpperTriangular(array, rows) and !isZeroMatrix(array, rows))
        {
          output << "True\n";
        }
        else if (isZeroMatrix(array, rows))
        {
          std::cout << "Zero matrix\n";
        }
        else if (!isZeroMatrix(array, rows))
        {
          output << "False\n";
        }
      }
      else
      {
        std::cout << "So small matrix\n";
      }
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
  else
  {
    int ** matrix = nullptr;
    try
    {
      matrix = goDynamicMatrix(input, rows, cols)
    }
    catch (const std::runtime_error & e)
    {
      std::cerr << e.what() << "\n";
      freeMatrix(matrix, rows, cols);
      return 2;
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << e.what() << "\n";
      freeMatrix(matrix, rows, cols);
      return 2;
    }
    try
    {
      if ((rows * cols) > 1)
      {
        if (isUpperTriangular(matrix, rows, cols) and !isZeroMatrix(matrix, rows, cols))
        {
          output << "True\n";
        }
        else if (isZeroMatrix(matrix, rows, cols))
        {
          std::cout << "Zero matrix\n";
        }
        else if (!isZeroMatrix(matrix, rows, cols))
        {
          output << "False\n";
        }
      }
      else
      {
        std::cout << "So small matrix\n";
      }
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      freeMatrix(matrix, rows, cols);
      return 2;
    }
    freeMatrix(matrix, rows, cols);
  }
  return 0;
}
