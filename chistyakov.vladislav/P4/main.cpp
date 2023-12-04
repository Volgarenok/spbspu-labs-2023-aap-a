#include <iostream>
#include <fstream>
#include <string>
#include "countLocalMinimums.hpp"
#include "inputArray.hpp"

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

  if (((taskNumber != 1) && (taskNumber != 2)) || argv[1][1] != 0)
  {
    std::cerr << "First argument must be only digit!\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t cols = 0;
  size_t rows = 0;

  input >> cols >> rows;
  if (!input)
  {
    std::cerr << "Cannot parse number of column or rows\n";
    return 2;
  }

  int * array = nullptr;
  int a[10000] = {};

  if (taskNumber == 1)
  {
    array = a;
  }
  else
  {
    array = new int[rows * cols];
  }

  size_t numOfElements = 0;

  numOfElements = inputArray(input, array, (rows * cols), (rows * cols));
  if (numOfElements != (rows * cols))
  {
    std::cerr << "Cannot parse numbers from file\n";
    if (taskNumber == 2)
    {
      delete[] array;
    }
    return 2;
  }

  size_t result = 0;
  result = countLocalMinimums(array, rows, cols);

  if (taskNumber == 2)
  {
    delete[] array;
  }

  std::ofstream output(argv[3]);
  output << result;

  return 0;
}
