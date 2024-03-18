#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.hpp"
#include "matrix_input_res.hpp"

int main(int argc, char * argv[])
{
  using namespace sakovskaia;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  char * endptr = nullptr;
  int num = 0;
  try
  {
    num = std::strtoll(argv[1], std::addressof(endptr), 10);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot read first argument\n";
    return 1;
  }
  if (*endptr != '\0')
  {
    std::cerr << "First argument error\n";
    return 1;
  }
  if ((num > 2) || (num < 1))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t rows = 0, columns = 0;
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Error in reading input file\n";
    return 2;
  }

  if ((rows == 0) or (columns == 0))
  {
    return 0;
  }

  std::ofstream output(argv[3]);

  int * input_matrix = nullptr;
  int * counterclockwise_matrix = nullptr;
  int * new_dynamic_matrix = nullptr;
  int * new_dynamic_counterclockwise_matrix = nullptr;
  int new_input_matrix[10000] = {};
  int new_counterclockwise_matrix[10000] = {};

  try
  {
    if (num == 1)
    {
      input_matrix = new_input_matrix;
      counterclockwise_matrix = new_counterclockwise_matrix;
    }
    else if (num == 2)
    {
      input_matrix = new int[rows * columns];
      counterclockwise_matrix = new int[rows * columns];
      new_dynamic_matrix = input_matrix;
      new_dynamic_counterclockwise_matrix = counterclockwise_matrix;
    }
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    delete [] input_matrix;
    delete [] counterclockwise_matrix;
    return 2;
  }

  try
  {
    inputMatrix(input, input_matrix, rows * columns);
    countCounterclockwiseMatrix(counterclockwise_matrix, rows, columns);
    countAnswer(input_matrix, counterclockwise_matrix, rows * columns);
    output << rows << " " << columns << " ";
    printAnswer(output, input_matrix, rows * columns);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    if (num == 2)
    {
      delete [] new_dynamic_matrix;
      delete [] new_dynamic_counterclockwise_matrix;
    }
    return 2;
  }
  if (num == 2)
  {
    delete [] new_dynamic_matrix;
    delete [] new_dynamic_counterclockwise_matrix;
  }
}
