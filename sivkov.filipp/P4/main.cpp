#include <fstream>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include "matrix.hpp"

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
  int ** rowsptrs = nullptr;
  try
  {
    rowsptrs = createMatrix(rows, cols);
    freeMatrix(rowsptrs, rows);
    }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Not enough memory\n";
    return 2;
  }
}
