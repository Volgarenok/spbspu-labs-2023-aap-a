#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "readMatrix.hpp"
#include "findRowThatHasABigSeries.hpp"

int main(int argc, char* argv[])
{
  int taskNumber = 0;
  size_t rows = 0;
  size_t cols = 0;

  if (argc != 4)
  {
    std::cerr << "Not enough parameters\n";
    return 2;
  }

  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);

  taskNumber = std::atoi(argv[1]);

  in >> rows >> cols;

  if (!in)
  {
    std::cerr << "Error read size of matrix\n";
    return 2;
  }

  size_t sizeArray = rows * cols;
  int rangedMatrix[10000] = {};
  int* matrix = nullptr;

  if (taskNumber != 1 && taskNumber != 2)
  {
    std::cerr << "Non-correct task number\n";
    return 2;
  }

  try
  {
    if (taskNumber == 1)
    {
      matrix = new int[sizeArray];
    }
    else
    {
      matrix = rangedMatrix;
    }
    serter::readMatrix(in, matrix, sizeArray);
    size_t result = serter::findRowThatHasABigSeries(matrix, rows, cols);
    out << '\n' << result;
    if (!out)
    {
      throw std::invalid_argument("Error of output result\n");
    }
  }
  catch (const std::exception& e)
  {
    if (taskNumber == 1)
    {
      delete[] matrix;
    }
    std::cerr << e.what() << '\n';
    return 1;
  }

  if (taskNumber == 1)
  {
    delete[] matrix;
  }

  return 0;
}

