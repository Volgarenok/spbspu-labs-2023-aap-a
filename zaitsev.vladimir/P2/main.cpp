#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <iomanip>

void read_matrix(std::ifstream& input, double* destination, size_t size)
{
  size_t counter = 0;

  for (size_t i = 0; i < size; ++i)
  {
    input >> *destination;
    ++destination;
    if (input)
    {
      ++counter;
    }
  }
  char check_size = '\0';
  input >> check_size;
  if (counter!=size||input)
  {
    throw std::range_error("Input data is not desired matrix");
  }
  return;
}

double smooth_matrix_element(const double* matrix, size_t n_rows, size_t n_cols, size_t row, size_t col)
{
  double res = 0;
  double divider = (3 - (row == 0 || row == n_rows - 1)) * (3 - (col == 0 || col == n_cols - 1)) - 1;
  for (size_t i = (row > 0 ? row - 1 : 0); i <= (row < n_rows - 1 ? row + 1 : row); ++i)
  {
    for (size_t j = (col > 0 ? col - 1 : 0); j <= (col < n_cols - 1 ? col + 1 : col); ++j)
    {
      if (i != row || j != col)
      {
        res += matrix[i * n_cols + j] / divider;
      }
    }
  }
  return res;
}

void smooth_matrix(const double* matrix, double* smoothed_matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      smoothed_matrix[i * cols + j] = smooth_matrix_element(matrix, rows, cols, i, j);
    }
  }
  return;
}

std::ofstream& write_matrix(std::ofstream& output, const double* destination, size_t size)
{

  for (size_t i = 0; i < size; ++i)
  {
    output.precision(1);
    output <<std::fixed<< *destination << " ";
    ++destination;
  }
  return output;
}

int main(int argc, char* argv[])
{
  if(argc==2)
  {
    return 0;
  }

  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }

  char* ptr = nullptr;
  long task_nmb = std::strtol(argv[1], &ptr, 10);

  if (task_nmb == 0 && ptr == argv[1])
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if (task_nmb > 2 || task_nmb < 1)
  {
    std::cerr << "First parameter is out of range\n";
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
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Matrix can't be read\n";
      return 2;
    }

    try
    {
      read_matrix(input, matrix, rows * cols);
    }
    catch (const std::range_error& e)
    {
      std::cerr << e.what() << "\n";
      input.close();
      return 2;
    }
    input.close();
    double smoothed_matrix[capacity];
    smooth_matrix(matrix, smoothed_matrix, rows, cols);
    output << rows << " " << cols<<" ";
    write_matrix(output, smoothed_matrix, rows * cols);
    output.close();
  }
  else
  {
    size_t cols = 0;
    size_t rows = 0;
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Matrix can't be read\n";
      return 2;
    }

    double* matrix = nullptr;
    try
    {
      matrix = new double[rows * cols];
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Failed to create matrix\n";
      return 2;
    }
    try
    {
      read_matrix(input, matrix, rows*cols);
    }
    catch (const std::range_error& e)
    {
      std::cerr << e.what() << "\n";
      input.close();
      return 2;
    }
    input.close();
    double* smoothed_matrix = nullptr;
    try
    {
      smoothed_matrix = new double[rows * cols];
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Failed to create matrix\n";
      input.close();
      delete[] matrix;
      return 2;
    }
    smooth_matrix(matrix, smoothed_matrix, rows, cols);
    output << rows << " " << cols<<" ";
    write_matrix(output, smoothed_matrix, rows * cols);
    output.close();
    delete[] matrix;
    delete[] smoothed_matrix;
  }
  return 0;
}
