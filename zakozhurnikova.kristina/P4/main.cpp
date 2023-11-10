#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char * argv[])
{
  int option = 0;
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
  const int s = rows * cols;
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
    int matrix[s]{};
    int original[s]{};
    zakozhurnikova::fillMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        input >> original[i*cols + j];
      }
    }
    zakozhurnikova::substractMatrix(original, matrix, rows, cols);
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        std::cout << original[i*rows + j] << ' ';
      }
      std::cout << '\n';
    }
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

