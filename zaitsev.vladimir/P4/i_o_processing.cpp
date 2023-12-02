#include "i_o_processing.h"

long zaitsev::checkArguments(int argc, const char* const* argv)
{
  if (argc > 4)
  {
    throw std::out_of_range("Too many arguments");
  }
  if (argc < 4)
  {
    throw std::out_of_range("Not enough arguments");
  }

  char* ptr = nullptr;
  long task_nmb = std::strtol(argv[1], std::addressof(ptr), 10);

  if (task_nmb == 0 && ptr == argv[1])
  {
    throw std::out_of_range("First parameter is not a number");
  }
  if (task_nmb > 2 || task_nmb < 1)
  {
    throw std::out_of_range("First parameter is out of range");
  }
  return task_nmb;
}

std::istream& zaitsev::readMatrix(std::istream& input, int* destination, size_t rows, size_t cols)
{
  size_t counter = 0;
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> *destination;
    ++destination;
    if (input)
    {
      ++counter;
    }
  }
  if (counter != rows * cols)
  {
    throw std::range_error("Input data is not desired matrix");
  }
  return input;
}

std::ostream& zaitsev::writeMatrix(std::ostream& output, const double* destination, size_t rows, size_t cols)
{
  std::ios format_holder(nullptr);
  format_holder.copyfmt(output);
  output << rows << " " << cols;
  output.precision(1);
  output.setf(std::ios::fixed);
  for (size_t i = 0; i < rows * cols; ++i)
  {
    output << " " << *destination;
    ++destination;
  }
  output.copyfmt(format_holder);
  return output;
}
