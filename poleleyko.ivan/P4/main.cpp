#include <iostream>
#include <fstream>
#include <cstddef>
#include <stdexcept>

#include "read_matrix.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  int number_of_task = 0;
  size_t count_of_rows = 0;
  size_t count_of_cols = 0;

  if (argc != 4)
  {
    std::cerr << "Invalid count of parameters\n";
    return 1;
  }

  number_of_task = std::atoi(argv[1]);

  if (number_of_task != 1 && number_of_task != 2)
  {
    std::cerr << "Incorrect number of task";
    return 2;
  }

  std::ifstream input_stream(argv[2]);
  std::ofstream output_stream(argv[3]);

  input_stream >> count_of_rows >> count_of_cols;

  if (!input_stream)
  {
    std::cerr << "Error input\n";
    return 1;
  }

  size_t size_of_array = count_of_rows * count_of_cols;
  int based_matrix[10000] = {};
  int* array = nullptr;

  try
  {

    if (number_of_task == 1)
    {
      array = new int[size_of_array];
    }
    else
    {
      array = based_matrix;
    }

    poleleyko::read_matrix(input_stream, array, size_of_array);
    poleleyko::spiral_matrix_transformation(array, count_of_rows, count_of_cols);

    output_stream << count_of_rows << count_of_cols << array << '\n'
    << poleleyko::count_row_not_same_numbers(array, count_of_rows, count_of_cols);

    if (!output_stream)
    {
      if (number_of_task == 1)
      {
        array = new int[size_of_array];
      }
      std::cerr << "Error output\n";
      return 1;
    }


  }
  catch (const std::exception& e)
  {
    if (number_of_task == 1)
    {
      delete[] array;
    }

    std::cerr << e.what() << '\n';

    return 1;
  }

  if (number_of_task == 1)
  {
    delete[] array;
  }

  return 0;
}
