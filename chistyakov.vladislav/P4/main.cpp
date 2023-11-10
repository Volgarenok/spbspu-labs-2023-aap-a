#include "countLocalMinimums.cpp"
#include "inputArray.cpp"
#include <iostream>
#include <fstream>
#include <string>

void printArray(int * array, int cols, int rows)
{
  for (int i = 0; i < cols * rows; ++i)
  {
    if (i % cols == 0 and i != 0)
    {
      std::cout << "\n";
    }
    std::cout << array[i] << "\t";
  }
  std::cout << "\n";
}


int main(int argc, char** argv)
{
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

      input >> cols;
      input >> rows;
      if (!input)
      {
        std::cerr << "Cannot parse number of column or rows\n";
        return 2;
      }

      int array[cols * rows];
      int number = 0;
      for (int i = 0; i < (cols * rows); ++i)
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

      std::cout << "CNT-LOC-MIN: " << result << "\n";
      printArray(array, cols, rows);
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
    int number = 0;
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

    std::cout << "CNT-LOC-MIN: " << result << "\n";
    printArray(array, cols, rows);
    delete [] array;
  }
  else
  {
    std::cerr << "Cannot parse values\n";
    return 1;
  }
}
