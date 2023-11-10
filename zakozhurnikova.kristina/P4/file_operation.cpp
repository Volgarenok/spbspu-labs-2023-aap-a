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
void zakozhurnikova::createMatrix(int **&matrix, int rows, int cols)
{
  matrix = new int *[rows]
  { nullptr };
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = new int[cols] {0};
  }
}

void zakozhurnikova::freeMatrix(int **&matrix, int rows)
{
  for (int i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
    delete[] matrix;
}
