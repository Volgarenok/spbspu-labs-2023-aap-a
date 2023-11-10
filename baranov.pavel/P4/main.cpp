#include <iostream>
#include <fstream>
#include <cstdlib>

void inputMatrix(std::istream & input, int * matrix, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (!(input >> matrix[i]))
    {
      throw std::length_error("Can not read matrix element");
    }
  }
}

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  unsigned char task = 0;
  try
  {
    task = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Valuue of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  if (task != 1 && task != 2)
  {
    std::cerr << "Incorrect task number\n";
    return 1;
  }

  unsigned int rows = 0;
  unsigned int columns = 0;
  {
    std::fstream input(argv[2]);
    input >> rows >> columns;
    if (!input)
    {
      std::cerr << "Incorrect parametrs for matrix\n";
      return 2;
    }

    if (task == 1)
    {
      int matrix[rows * columns] = {0};
      try
      {
        inputMatrix(input, matrix, rows * columns);
      }
      catch (...)
      {
        std::cerr << "Can not read matrix\n";
        return 2;
      }
      for (unsigned int i = 0; i < rows * columns; ++i)
      {
        std::cout << matrix[i] << '\n';
      }
    }
  }
}
