#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char * argv[])
{
  int num = 0;
  try
  {
    zakozhurnikova::rightArguments(argc, argv);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }
  if (num == 1)
  {
    const size_t mSize = 10000;
    double matrix[mSize];
     try
    {
      zakozhurnikova::inputMatrix(input, matrix, rows, cols);
    }
    catch (const std::range_error& e)
    {
      std::cerr << e.what() << "\n";
      input.close();
      return 2;
    }
    input.close();
    //cod1
  }
  else
  {
    double* matrix = nullptr;
    matrix = new double[rows * cols];
    if (!matrix)
    {
      std::cerr << "Failed to create matrix\n";
      return 2;
    }
    try
    {
      zakozhurnikova::inputMatrix(input, matrix, rows, cols);
    }
    catch (const std::range_error& e)
    {
      std::cerr << e.what() << "\n";
      input.close();
      delete[] matrix;
      return 2;
    }
    input.close();
  }
  return 0;
}

//namespace.cpp
int zakozhurnikova::rightArguments(int argc, char** argv)
{
  if (argc != 4)
  {
    throw std::invalid_argument("Error in command line arguments\n");
    return 1;
  }
  char* ptr = nullptr;
  int num = std::strtol(argv[1], &ptr, 10);
  if (num == 0 && ptr == argv[1])
  {
    throw std::invalid_argument("First parameter is not a number");
    return 1;
  }
  if (num != 2 && num != 1)
  {
    throw std::invalid_argument("First parameter is not 1 and 2");
    return 1;
  }
  return num;
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

