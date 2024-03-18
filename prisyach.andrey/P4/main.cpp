#include "process_matrix.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  int task_number = 0;

  try
  {
    size_t next_char_index = 0;
    task_number = std::stoi(argv[1], std::addressof (next_char_index));

    if (argv[1][next_char_index] != '\0')
    {
      throw std::invalid_argument("Invalid characters in the first command line argument");
    }
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of the first comand line argument is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "The first argument is not a number\n";
    return 1;
  }

  if (task_number != 1 && task_number != 2)
  {
    std::cerr << "Number of the task is wrong\n";
    return 1;
  }

  std::ifstream input_file(argv[2]);

  if (!input_file)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }

  size_t rows = 0, cols = 0;

  if (!(input_file >> rows >> cols))
  {
    std::cerr << "Error reading rows and cols from file\n";
    return 2;
  }

  std::ofstream output_file(argv[3]);

  if (cols == 0 || rows == 0)
  {
    output_file << "0\n";
    return 0;
  }

  int max_matrix_size[10000] = {0};
  int * matrix = nullptr;

  if (task_number == 1)
  {
    matrix = max_matrix_size;
  }
  else
  {
    matrix = new int[rows * cols]{0};
  }

  try
  {
    prisyach::readMatrix(input_file, matrix, rows, cols);
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error" << e.what() << "\n";
    if (task_number == 2)
    {
      delete[] matrix;
    }
    return 2;
  }

  int result = prisyach::findMaxSequence(matrix, rows, cols);

  if (task_number == 2)
  {
    delete[] matrix;
  }

  if (!output_file)
  {
    std::cerr << "Error opening output file\n";
    return 2;
  }

  output_file << result + 1 << "\n";
  return 0;
}
