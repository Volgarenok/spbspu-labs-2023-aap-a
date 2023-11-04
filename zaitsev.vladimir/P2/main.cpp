#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <fstream>


int main(int argc, char* argv[])
{
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

  if (task_nmb == 1)
  {
    const size_t capacity = 10000;
    double matrix[capacity];
    for (size_t i = 0; i < capacity; ++i)
    {
      matrix[i] = 0;
    }
    size_t cols = 0;
    size_t rows = 0;
    input >> cols >> rows;
    if (!input)
    {
      std::cerr << "Matrix can't be read\n";
      return 2;
    }
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
  }
  return 0;
}
