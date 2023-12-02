#include "file_operation.h"

int zakozhurnikova::checkArguments(int argc, const char **const argv)
{
  if (argc != 4)
  {
    throw std::invalid_argument("Error in command line arguments\n");
  }
  const char *arg = argv[1];
  while (*arg)
  {
    if (!std::isdigit(*arg))
    {
      throw std::invalid_argument("");
    }
    arg++;
  }
  char* ptr = nullptr;
  int option = std::strtol(argv[1], std::addressof(ptr), 10);
  if (option != 2 && option != 1)
  {
    throw std::invalid_argument("First parameter is not 1 and 2");
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
