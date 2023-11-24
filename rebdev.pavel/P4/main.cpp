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
  else if (inputFile.peek() == EOF)
  {
    inputFile.close();
    return 2;
  }

  int rows = 0, colums = 0;
  try
  {
    inputFile >> rows;
    if ((rows == 0) && (inputFile.peek() == EOF || (inputFile.peek() == 10)))
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

  if (rows > std::numeric_limits<long int>::max()/colums)
  {
    inputFile.close();
    return 2;
  }

  using namespace rebdev;
  if (arrayMode == 1)
  {
    long long int array[rows * colums];
    try
    {
      filling(array, rows, colums, inputFile);
      std::ofstream outputFile(argv[3]);
      if (!outputFile.is_open())
      {
        return 2;
      }
      outputFile << localMax(array, rows, colums);
      outputFile.close();
    }
    catch (const std::logic_error & e)
    {
      return 2;
    }
  }
  else
  {
    unsigned long int num = rows * colums;
    long long int * array = new long long int[num];
    try
    {
      filling(array, rows, colums, inputFile);
      std::ofstream outputFile(argv[3]);
      if (!outputFile.is_open())
      {
        return 2;
      }
      outputFile << localMax(array, rows, colums);
      outputFile.close();
      delete [] array;
    }
    catch (const std::logic_error & e)
    {
      delete [] array;
      return 2;
    }
  }

  inputFile.close();
  return 0;
}
