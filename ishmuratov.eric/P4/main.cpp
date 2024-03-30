#include <fstream>
#include <cstdlib>
#include "matrix_input.hpp"
#include "trimatrix_check.hpp"
#include "numrow_check.hpp"

int main(int argc, char ** argv)
{
  using namespace ishmuratov;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }

  int fixedMatrix[10000] = {};
  int * dynamicMatrix = nullptr;
  int * matrix = nullptr;

  if (num == 1)
  {
    matrix = fixedMatrix;
  }
  else if (num == 2)
  {
    dynamicMatrix = new int[rows * cols];
    matrix = dynamicMatrix;
  }
  else
  {
    std::cerr << "Number of a task must be 1 or 2!\n";
  }

  try
  {
    ishmuratov::matrixInput(input, matrix, rows, cols);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    delete [] dynamicMatrix;
    return 2;
  }

  std::ofstream output(argv[3]);

  output << std::boolalpha << ishmuratov::lowerMatrixCheck(matrix, rows, cols) << "\n";
  output << ishmuratov::checkRow(matrix, rows, cols) << "\n";

  delete [] dynamicMatrix;
}
