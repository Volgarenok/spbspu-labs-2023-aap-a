#include "file_operation.h"

int zakozhurnikova::rightArgument(const char *arg)
{
  while (*arg)
  {
    if (!isdigit(*arg))
    {
      return 0;
    }
    arg++;
  }
  return -1;
}

int zakozhurnikova::rightArguments(int argc, const char** argv)
{
  if (argc != 4)
  {
    throw std::invalid_argument("Error in command line arguments\n");
    return 1;
  }
  char* ptr = nullptr;
  int option = std::strtol(argv[1], &ptr, 10);
  if (!rightArgument(argv[1]))
  {
    throw std::invalid_argument("First parameter is not a number");
    return 1;
  }
  if (option != 2 && option != 1)
  {
    throw std::invalid_argument("First parameter is not 1 and 2");
    return 1;
  }
  return option;
}

void zakozhurnikova::writeToFile(std::ofstream& out, int *matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols - 1; i++)
  {
    out << matrix[i] << ' ';
  }
  out << matrix[rows * cols - 1];
}
