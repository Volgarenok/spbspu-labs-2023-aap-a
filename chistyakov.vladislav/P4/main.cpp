#include <iostream>
#include <fstream>
#include <string>
#include "countLocalMinimums.hpp"
#include "inputArray.hpp"

void writeAnswerInFile(int answer,char * outputFile)
{
  std::ofstream output(outputFile);
  output << answer;
}

int main(int argc, char** argv)
{
  using namespace chistyakov;

  if (argc != 4)
  {
    std::cerr << "Bad input arguments\n";
    return 1;
  }

  int taskNumber = 0;
  try
  {
    taskNumber = std::stoll(argv[1]);
  }
  catch (...)
  {
    std::cerr << "Cannot parse values\n";
    return 1;
  }

  if (taskNumber == 1)
  {
    {
      std::ifstream input(argv[2]);
      size_t cols = 0;
      size_t rows = 0;

      input >> cols >> rows;
      if (!input)
      {
        std::cerr << "Cannot parse number of column or rows\n";
        return 2;
      }

      int array[cols * rows];
      int number = 0;
      for (size_t i = 0; i < (cols * rows); ++i)
      {
        input >> number;
        if (!input)
        {
          std::cerr << "Cannot parse number from file\n";
          return 2;
        }
        array[i] = number;
      }

      size_t result = 0;
      result = countLocalMinimums(array, rows, cols);
      writeAnswerInFile(result, argv[3]);

      return 0;
    }
  }
  else if (taskNumber == 2)
  {
    std::ifstream input(argv[2]);

    size_t cols = 0;
    size_t rows = 0;

    input >> cols >> rows;

    if (!input)
    {
      std::cerr << "Cannot parse number of column or rows\n";
      return 2;
    }

    int * array = new int[rows * cols];
    size_t numOfElements = 0;

    numOfElements = inputArray(input, array, (rows * cols), (rows * cols));
    if (numOfElements != (rows * cols))
    {
      std::cerr << "Cannot parse numbers from file\n";
      delete [] array;
      return 2;
    }

    size_t result = 0;
    result = countLocalMinimums(array, rows, cols);

    delete [] array;

    writeAnswerInFile(result, argv[3]);
    return 0;
  }
  else
  {
    std::cerr << "Values is not 1 or 2\n";
    return 1;
  }
}
