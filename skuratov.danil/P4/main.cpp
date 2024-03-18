#include <cctype>
#include <string>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "countSaddlePoints.h"
#include "findLongestSeriesRow.h"
#include "findMinSumAlongSecondaryDiagonal.h"
#include "readArray.h"

int main(int argc, char* argv[])
{
  using namespace skuratov;
  size_t rows = 1;
  size_t cols = 1;
  if (argc < 4)
  {
    std::cerr << "Not enough parameters" << '\n';
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments" << '\n';
    return 1;
  }
  int taskNumber = 0;
  try
  {
    taskNumber = std::stoi(argv[1]);
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "Value of first CLA is too large" << '\n';
    return 1;
  }

  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);

  if (!in.is_open())
  {
    std::cerr << "Cannot open file!" << '\n';
    return 2;
  }
  if (!in)
  {
    std::cerr << "Cannot read numbers!" << '\n';
    return 2;
  }

  in >> rows >> cols;

  if (rows == 0 && cols == 0)
  {
    return 0;
  }

  if (in.eof())
  {
    std::cerr << "Error data!" << '\n';
    return 2;
  }
  int nonDynamicArray[10000] = {};
  int* dynamicArray = nullptr;
  int* matrix = nullptr;

  if (taskNumber == 1)
  {
    matrix = nonDynamicArray;
  }
  else
  {
    try
    {
      dynamicArray = new int[rows * cols];
      matrix = dynamicArray;
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "error array" << '\n';
      delete[] dynamicArray;
      return 2;
    }
  }
  size_t res1 = 0;
  size_t res2 = 0;
  size_t res3 = 0;

  try
  {
    readArray(in, matrix, rows, cols);
    res1 = findLongestSeriesRow(matrix, rows, cols);
    res2 = findMinSumAlongSecondaryDiagonal(matrix, rows, cols);
    res3 = countSaddlePoints(matrix, rows, cols);
  }
  catch (const std::logic_error&)
  {
    std::cerr << "bad data" << '\n';
    if (taskNumber == 2)
    {
      delete[] matrix;
    }
    return 2;
  }

  out << res1 << ' ' << res2 << ' ' << res3 << '\n';

  if (taskNumber == 2)
  {
    delete[] matrix;
  }
  return 0;
}
