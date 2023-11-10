#include <iostream>
#include <fstream>
#include <limits>
#include "matrix.hpp"
#include "forFile.hpp"

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
    //std::cerr << "can't open input file!";
    return 2;
  }
  else if (inputFile.peek() == EOF)
  {
    inputFile.close();
    //std::cerr << "Input file is empty!";
    return 2;
  }

  long long int rows = 0, colums = 0;
  try
  {
    rows = readFromFileLLI(inputFile);
    colums = readFromFileLLI(inputFile);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 2;
  }
  if ((rows == 0) || (colums == 0))
  {
    inputFile.close();
    //std::cerr << "matrix size can't be [0][0]!";
    return (((rows || colums) == 0) ? 0 : 2);
  }

  if (rows > std::numeric_limits<long long int>::max()/colums)
  {
    inputFile.close();
    //std::cerr << "The array is too large!";
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
        //std::cerr << "Can't open output file"
        return 2;
      }
      outputFile << localMax(array, rows, colums);
      outputFile.close();
    }
    catch (const std::logic_error & e)
    {
      //std::cerr << e.what();
      return 2;
    }
  }
  else
  {
    long long int * array = new long long int [rows * colums];
    try
    {
      filling(array, rows, colums, inputFile);
      std::ofstream outputFile(argv[3]);
      if (!outputFile.is_open())
      {
        //std::cerr << "Can't open output file";
        return 2;
      }
      outputFile << localMax(array, rows, colums);
      outputFile.close();
    }
    catch (const std::logic_error & e)
    {
      delete [] array;
      //std::cerr << e.what();
      return 2;
    }
  }

  inputFile.close();
  return 0;
}
