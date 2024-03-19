#include <iostream>
#include <fstream>
#include "input.h"
#include "output.h"
#include "smoothed.h"
#include "topclock.h"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Invalid amount of arguments\n";
    return 1;
  }

  int arrType = 0;
  try
  {
    arrType = std::stoi(argv[1]);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Invalid first argument\n";
    return 1;
  }

  if (arrType != 1 && arrType != 2)
  {
    std::cerr << "First argument can only be '1' or '2'\n";
    return 1;
  }

  std::ifstream iFile(argv[2]);
  if (!iFile.is_open())
  {
    std::cerr << "Couldn't open input file\n";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;

  iFile >> rows >> cols;
  if (!iFile)
  {
    std::cerr << "Couldn't read file\n";
    return 2;
  }
  if (rows == 0 && cols == 0)
  {
    return 0;
  }
  else if (rows * cols == 0 || cols != rows)
  {
    std::cerr << "Invalid Matrix dimensions\n";
    return 2;
  }
  else
  {
    int *matrix = nullptr;
    double *smooth = nullptr;

    int fixedArray[10000] = {};
    double smoothArray[10000] = {};

    if (arrType == 1)
    {
      matrix = fixedArray;
      smooth = smoothArray;
    }
    else
    {
      try
      {
        matrix = new int[cols * rows];
        smooth = new double[cols * rows];
      }
      catch (const std::bad_alloc &e)
      {
        std::cerr << "Error while allocating dynamic array\n";
        delete[] matrix;
        delete[] smooth;
        return 2;
      }
    }
    try
    {
      skopchenko::input(iFile, matrix, rows, cols);
    }
    catch (const std::logic_error &e)
    {
      std::cerr << "Couldn't input matrix\n";
      if (arrType == 2)
      {
        delete[] matrix;
        delete[] smooth;
      }
      return 2;
    }

    std::ofstream oFile(argv[3]);
    if (!oFile.is_open())
    {
      std::cerr << "Couldn't open output file\n";
      return 2;
    }

    skopchenko::makeSmoothMatrix(matrix, smooth, rows, cols);
    try
    {
      skopchenko::outputDouble(oFile, smooth, rows, cols);
      oFile << "\n";
    }
    catch (const std::runtime_error &e)
    {
      std::cerr << "Couldn't output matrix\n";
      if (arrType == 2)
      {
        delete[] matrix;
        delete[] smooth;
      }
      return 2;
    }
    skopchenko::goClockwiseShort(matrix, rows, cols);
    try
    {
      skopchenko::outputInt(oFile, matrix, rows, cols);
      oFile << "\n";
    }
    catch (const std::runtime_error &e)
    {
      std::cerr << "Couldn't output matrix\n";
      if (arrType == 2)
      {
        delete[] matrix;
        delete[] smooth;
      }
      return 2;
    }

    if (arrType == 2)
    {
      delete[] matrix;
      delete[] smooth;
    }
  }
}
