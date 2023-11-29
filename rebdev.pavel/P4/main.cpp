#include <fstream>
#include <limits>
#include <iostream>
#include "matrix.hpp"
#include "readFromFile.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    return 1;
  }
  int arrayMode = std::stoi(argv[1]);
  if ((arrayMode != 1) && (arrayMode != 2))
  {
    return 1;
  }

  std::ifstream inputFile(argv[2]);
  if (!inputFile.is_open())
  {
    return 2;
  }

  int rows = 0, colums = 0;
  try
  {
    inputFile >> rows;
    if (rows == 0)
    {
      return 0;
    }

    inputFile >> colums;

    if (!inputFile)
    {
      return 2;
    }
  }
  catch (const std::logic_error & e)
  {
    return 2;
  }
  if ((rows == 0) || (colums == 0))
  {
    inputFile.close();
    return (((rows || colums) == 0) ? 0 : 2);
  }

  if (rows > (std::numeric_limits<long int>::max() / colums))
  {
    inputFile.close();
    return 2;
  }

  using namespace rebdev;
  long long int * array = nullptr;
  if (arrayMode == 1)
  {
    array[rows * colums];
  }
  else
  {
    unsigned long int num = rows * colums;
    array = new long long int[num];
  }

  try
  {
    filling(array, rows, colums, inputFile);
    std::ofstream outputFile(argv[3]);
    if (!outputFile.is_open())
    {
      return 2;
    }
    outputFile << findNumberOfLocalMax(array, rows, colums);
    outputFile.close();
    if (arrayMode != 1)
    {
      delete [] array;
    }
  }
  catch (const std::logic_error & e)
  {
    delete [] array;
    return 2;
  }
  catch (const size_t & i)
  {
    std::cerr << i << "elements is writing\n";
    return 2;
  }

  inputFile.close();
  return 0;
}
