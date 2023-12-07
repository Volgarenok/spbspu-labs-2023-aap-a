#include "file_operation.h"

int zakozhurnikova::checkArguments(int argc, const char **const argv)
{
  if (argc != 4)
  {
    throw std::invalid_argument("Error in command line arguments\n");
  }
  char* ptr = nullptr;
  int option = std::strtoll(argv[1], std::addressof(ptr), 10);
  if(*ptr != '\0')
  {
    throw std::invalid_argument("First argument is not a number");
  }
  if (option != 2 && option != 1)
  {
    throw std::invalid_argument("First parameter is not 1 and 2");
  }
  return option;
}

void zakozhurnikova::writeToDest(std::ostream& out, const int *matrix, size_t rows, size_t cols)
{
  if (rows == 0 && cols == 0)
  {
    out << "0 0"
    return;
  }
  else if (rows == 0 && cols != 0) || (rows != 0 && cols == 0))
  {
    throw std::invalid_argument("Such matrix can not exist\n");
  }
  for (size_t i = 0; i < rows * cols - 1; i++)
  {
    out << matrix[i] << ' ';
  }
  out << matrix[rows * cols - 1];
}
