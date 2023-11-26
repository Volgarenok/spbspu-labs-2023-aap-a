#include "task.h"

#include <algorithm>
#include <fstream>
#include <cstddef>
#include <iostream>
#include <climits>

#include "bubbleSort.h"
#include "matrix.h"

namespace skuratov
{
  int countSaddlePoints(const int* matrix, size_t width, size_t height)
  {
    int saddlePoints = 0;
    for (size_t row = 0; row < height; ++row)
    {
      for (size_t col = 0; col < width; ++col)
      {
        int currentElement = matrix[row * width + col];
        bool isSaddlePoint = true;
        for (size_t i = 0; i < width; ++i)
        {
          if (currentElement > matrix[row * width + i])
          {
            isSaddlePoint = false;
            break;
          }
        }
        for (size_t j = 0; j < height; ++j)
        {
          if (currentElement < matrix[j * width + col])
          {
            isSaddlePoint = false;
            break;
          }
        }
        if (isSaddlePoint)
        {
          ++saddlePoints;
        }
      }
    }
    return saddlePoints;
  }
  int minSumParallelDiagonals(const int* matrix, size_t width, size_t height)
  {
    int minSum = INT_MAX;
    for (size_t startCol = 0; startCol < width; ++startCol)
    {
      int sum = 0;
      size_t col = startCol;
      for (size_t row = 0; row < height && col < width; ++row, ++col)
      {
        sum += matrix[row * width + col];
      }
      if (sum < minSum)
      {
        minSum = sum;
      }
    }
    for (size_t startRow = 1; startRow < height; ++startRow)
    {
      int sum = 0;
      size_t row = startRow;
      for (size_t col = 0; col < width && row < height; ++row, ++col)
      {
        sum += matrix[row * width + col];
      }
      if (sum < minSum)
      {
        minSum = sum;
      }
    }
    return minSum;
  }
  void writeResult(int result, const std::string& fileName)
  {
    std::ofstream os(fileName);
    os << result;
    if (!os)
    {
      throw std::runtime_error("Can't write matrix to the file");
    }
  }
  void performTask(const Parameters& parameters)
  {
    size_t width = 0;
    size_t height = 0;
    readMatrixSizeFromFile(width, height, parameters.inputFileName);
    if (!width || !height)
    {
      return;
    }
    const size_t matrixArea = width * height;
    if (parameters.task == Parameters::Task::First)
    {
      const size_t MaxMatrixArea = 10000;
      if (matrixArea > MaxMatrixArea)
      {
        throw std::runtime_error("Matrix in file greater than MAX_SIZE");
      }
      int* matrixData = new int[matrixArea];
      try
      {
        readMatrixFromFile(matrixData, matrixArea, parameters.inputFileName);
        writeResult(countSaddlePoints(matrixData, width, height), parameters.outputFileName);
      }
      catch (const std::exception& e)
      {
        delete[] matrixData;
        throw;
      }
      delete[] matrixData;
    }
    if (parameters.task == Parameters::Task::Second)
    {
      int* matrixData = new int[matrixArea];
      try
      {
        readMatrixFromFile(matrixData, matrixArea, parameters.inputFileName);
        writeResult(minSumParallelDiagonals(matrixData, width, height), parameters.outputFileName);
      }
      catch (const std::exception& e)
      {
        delete[] matrixData;
        throw;
      }
      delete[] matrixData;
    }
  }
}
