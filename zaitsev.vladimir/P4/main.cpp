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
    zaitsev::checkArguments(argc, argv);
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

  if (task_nmb == 1)
  {
    const size_t capacity = 10000;
    double matrix[capacity];
    size_t cols = 0;
    size_t rows = 0;
    input >> cols >> rows;
    if (!input)
    {
      std::cerr << "Matrix can't be read\n";
      return 2;
    }
    try
    {
      zaitsev::readMatrix(input, matrix, rows * cols);
    }
    catch (const std::range_error& e)
    {
      std::cerr << e.what() << "\n";
      input.close();
      return 2;
    }
    input.close();
    double smoothed_matrix[capacity];
    zaitsev::smoothMatrix(matrix, smoothed_matrix, rows, cols);
    zaitsev::writeMatrix(output, smoothed_matrix, rows, cols);
    output.close();
  }
  else
  {
    size_t cols = 0;
    size_t rows = 0;
    input >> cols >> rows;
    if (!input)
    {
      std::cerr << "Matrix can't be read\n";
      return 2;
    }
    double* matrix = nullptr;
    matrix = new double[rows * cols];
    if (!matrix)
    {
      std::cerr << "Failed to create matrix\n";
      return 2;
    }
    try
    {
      zaitsev::readMatrix(input, matrix, rows * cols);
    }
    catch (const std::range_error& e)
    {
      std::cerr << e.what() << "\n";
      input.close();
      delete[] matrix;
      return 2;
    }
    input.close();
    double* smoothed_matrix = nullptr;
    smoothed_matrix = new double[rows * cols];
    if (!smoothed_matrix)
    {
      std::cerr << "Failed to create matrix\n";
      input.close();
      delete[] matrix;
      return 2;
    }
    zaitsev::smoothMatrix(matrix, smoothed_matrix, rows, cols);
    zaitsev::writeMatrix(output, smoothed_matrix, rows, cols);
    output.close();
    delete[] matrix;
    delete[] smoothed_matrix;
  }
  return 0;
}
