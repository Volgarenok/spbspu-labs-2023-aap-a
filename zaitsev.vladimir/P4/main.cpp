#include <iostream>
#include <fstream>
#include <cstddef>
#include "i_o_processing.h"
#include "matrix_processing.h"

int main(int argc, char** argv)
{
  long task_nmb = 0;
  try
  {
    task_nmb = zaitsev::checkArguments(argc, argv);
  }
  catch (const std::out_of_range& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "The input file can't be opened\n";
    return 2;
  }
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "The output file can't be opened\n";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;
  constexpr size_t capacity = 10000;
  int static_matrix[capacity] = {};
  int* matrix = nullptr;
  double* smoothed_matrix = nullptr;
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Matrix can't be read\n";
    return 2;
  }
  if (rows * cols == 0 && rows + cols > 0)
  {
    std::cerr << "Dimensions of the matrix are set incorrectly\n";
    return 2;
  }

  try
  {
    smoothed_matrix = new double[rows * cols];
    if (task_nmb == 1)
    {
      matrix = static_matrix;
    }
    else
    {
      matrix = new int[rows * cols];
    }
    zaitsev::readMatrix(input, matrix, rows, cols);
    zaitsev::smoothMatrix(matrix, smoothed_matrix, rows, cols);
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Failed to create matrix\n";
    delete[] smoothed_matrix;
    return 2;
  }
  catch (const std::range_error& e)
  {
    std::cerr << e.what() << "\n";
    delete[] smoothed_matrix;
    if (task_nmb == 2)
    {
      delete[] matrix;
    }
    return 2;
  }

  zaitsev::writeMatrix(output, smoothed_matrix, rows, cols) << "\n";
  delete[] smoothed_matrix;
  if (task_nmb == 2)
  {
    delete[] matrix;
  }
  return 0;
}
