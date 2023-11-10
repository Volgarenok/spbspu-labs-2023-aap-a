#include <fstream>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>

void freeMatrix(int** m, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] m[i];
  }
  delete[] m;
}

int ** createMatrix(size_t rows, size_t cols)
{
  int ** rowsptrs = new int* [rows];
  for (size_t i = 0; i < rows; ++i)
  {
    rowsptrs[i] = nullptr;
  }
  try
  {
    for (size_t i = 0; i < rows; ++i)
    {
      rowsptrs[i] = new int[cols];
    }
    return rowsptrs;
  }
  catch (const std::bad_alloc&)
  {
    freeMatrix(rowsptrs, rows, cols);
    throw;
  }
}

int main(int argc, char * argv[])
{
  //проверка на правильность ввода ком. строки
  if (argc != 4)
  {
    std::cout << "Error command line\n";
    return 1;
  }
  //argv[1] - номер задания
  int numOfTask = 0;
  try
  {
    numOfTask = std::stoi(argv[1]);
  }
  catch (const std::out_of_range&)
  {
  std::cerr << "Value of first CLA is too large\n";
  return 2;
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "Cannot parse a value\n";
    return 2;
  }
  if ((numOfTask != 1) && (numOfTask != 2))
  {
    std::cerr << "Error number of task";
  }
  //argv[2] - имя файла с матрицей
  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Cannot read a number!\n";
      return 2;
    }
  }
  int** rowsptrs = nullptr;
  try
  {
    rowsptrs = createMatrix(rows, cols);
    freeMatrix(rowsptrs, rows, cols);
    }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Not enough memory\n";
    return 2;
  }
}
