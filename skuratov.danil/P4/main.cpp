#include <iostream>
#include <fstream>
#include <cctype>
#include <cstddef>
#include <stdexcept>

#include "readArray.h"
#include "countSaddlePoints.h"
#include "findMinSumAlongSecondaryDiagonal.h"
#include "findLongestSeriesRow.h"

int main(int argc, char* argv[])
{
  using namespace skuratov;
  const size_t MAX_SIZE = 10000;
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
  int taskNumber = std::atoi(argv[1]);
  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);
  if (!in.is_open())
  {
    std::cerr << "Cannot open file!\n";
    return 2;
  }
  if (!in)
  {
    std::cerr << "Cannot read numbers!\n";
    return 2;
  }
  in >> rows >> cols;
  size_t sizeOfArray = rows * cols;
  if (rows == 0 && cols == 0)
  {
    return 0;
  }
  if (in.eof())
  {
    std::cerr << "Error data!" << '\n';
    return 2;
  }
  if ((sizeOfArray < MAX_SIZE) && (rows != 0 || cols != 0))
  {
    if (taskNumber == 1)
    {
      int staticArray[MAX_SIZE] = {};
      if (!readArray(in, staticArray, rows, cols))
      {
        return 1;
      }
      int res = countSaddlePoints(staticArray, rows, cols);
      out << res << '\n';
      if (!(out << res))
      {
        std::cerr << "Error output file" << '\n';
        return 2;
      }
      res = findMinSumAlongSecondaryDiagonal(staticArray, rows, cols);
      out << res << '\n';
      if (!(out << res))
      {
        std::cerr << "Error output file" << '\n';
        return 2;
      }
      res = findLongestSeriesRow(staticArray, rows, cols);
      out << res << '\n';
      if (!(out << res))
      {
        std::cerr << "Error output file" << '\n';
        return 2;
      }
    }
  }
  if (taskNumber == 2)
  {
    int* dynamicArray = new int[sizeOfArray];
    if (!readArray(in, dynamicArray, rows, cols))
    {
      return 1;
    }
    if (dynamicArray == nullptr)
    {
      return 1;
    }
    int res = countSaddlePoints(dynamicArray, rows, cols);
    out << res << '\n';
    if (!(out << res))
    {
      std::cerr << "Error output file" << '\n';
      delete[] dynamicArray;
      return 2;
    }
    res = findMinSumAlongSecondaryDiagonal(dynamicArray, rows, cols);
    out << res << '\n';
    if (!(out << res))
    {
      std::cerr << "Error output file" << '\n';
      delete[] dynamicArray;
      return 2;
    }
    res = findLongestSeriesRow(dynamicArray, rows, cols);
    out << res << '\n';
    if (!(out << res))
    {
      std::cerr << "Error output file" << '\n';
      delete[] dynamicArray;
      return 2;
    }
    delete[] dynamicArray;
  }
  return 0;
}
