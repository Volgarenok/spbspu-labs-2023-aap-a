#include "file_operation.h"

int zakozhurnikova::rightArguments(int argc, char** argv)
{
  if (argc != 4)
  {
    throw std::invalid_argument("Error in command line arguments\n");
    return 1;
  }
  char* ptr = nullptr;
  int option = std::strtol(argv[1], &ptr, 10);
  if (option == 0 && ptr == argv[1])
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
void zakozhurnikova::inputMatrix(std::ifstream& input, double* size, size_t rows, size_t cols)
{
  size_t account = 0;
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> *size;
    ++size;
    if (input)
    {
      ++account;
    }
  }
  char check_size = '\0';
  input >> check_size;
  if (account != rows * cols || input)
  {
    throw std::range_error("Input data is not desired matrix");
  }
  return;
}
