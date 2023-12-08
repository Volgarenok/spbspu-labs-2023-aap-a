#include <fstream>
#include <limits>
#include <iostream>
#include <cstring>

#include "matrix.hpp"
#include "readFromFile.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    return 1;
  }

  int arrayMode = 0;
  try
  {
    arrayMode = std::stoi(argv[1]);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "First param isn't number!\n";
    return 1;
  }

  if (((arrayMode != 1) && (arrayMode != 2)) || (argv[1][1] != 0))
  {
    std::cerr << "First param must be only number!\n";
    return 1;
  }

  std::ifstream inputFile(argv[2]);
  if (!inputFile.is_open())
  {
    return 2;
  }

  size_t rows = 0, colums = 0;
  try
  {
    inputFile >> rows;

    if (inputFile.eof())
    {
      std::cerr << "File is empty!\n";
      return 2;
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
    return (((rows || colums) == 0) ? 0 : 2);
  }

  if (rows > (std::numeric_limits< size_t >::max() / colums))
  {
    return 2;
  }

  long long int arr2[10000] = {0};
  long long int * array = nullptr;

  if (arrayMode == 1)
  {
    array = arr2;
  }
  else
  {
    array = new long long int[rows * colums];
  }

  try
  {
    size_t fillIsOk = rebdev::fillTheMatrix(array, rows, colums, inputFile);
    if (fillIsOk < (colums * rows))
    {
      std::cerr << fillIsOk << " elements is writing\n";
      if (arrayMode != 1)
      {
        delete [] array;
      }
      return 2;
    }

    std::ofstream outputFile(argv[3]);

    if (!outputFile.is_open())
    {
      if (arrayMode != 1)
      {
        delete [] array;
      }
      return 2;
    }

    outputFile << rebdev::findNumberOfLocalMax(array, rows, colums);
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

  return 0;
}
