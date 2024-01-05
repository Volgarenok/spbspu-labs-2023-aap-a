#include <iostream>
#include <fstream>

void freeMatrix(int ** m, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete [] m[i];
  }
  delete [] m;
}

int ** createMatrix(size_t rows, size_t cols)
{
  int ** rowsptrs = new int *[rows];
  for (size_t i = 0; i < rows; ++i)
    {
      rowsptrs[i] = new int[cols];
    }
    return rowsptrs;
}

size_t findMaxRow(int * matrix, size_t rows, size_t cols)
{
  size_t maxRow = 0;
  size_t max = 0;

  for (size_t i = 0; i < rows; ++i)
  {
    size_t localCount = 1;
    for (size_t j = 0; j < cols - 1; ++j)
    {
      if (matrix[i * cols + j] == matrix[i * cols + j + 1])
      {
        ++localCount;
        if (localCount > max)
        {
          max = localCount;
          maxRow = i + 1;
        }
      }
      else
      {
        localCount = 1;
      }
    }
  }
  return maxRow;
}

void processMatrix(int ** matrix, size_t rows, size_t cols, const char * number)
{
  size_t maxRow = findMaxRow(& matrix[0][0], rows, cols);

  std::ofstream output(number);
  output << maxRow;
}

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::atoi(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of the first comand line argument is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "The first argument is not a number\n";
    return  1;
  }

  if (num != 1 && num != 2)
  {
    std::cerr << "Number of the task is wrong\n";
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

  if (num == 1)
  {
    if (rows * cols > 10000)
    {
      std::cerr << "Size of the matrix exceeds the limit for a static array\n";
      return 1;
    }

    int * matrix = new int[rows * cols];

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[i * cols + j];
      }
    }
    processMatrix(& matrix, rows, cols, argv[3]);
    delete [] matrix;
  }

  else if (num == 2)
  {
    int *  matrix = new int[rows * cols];

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[i * rows + j];
      }
    }
    processMatrix(& matrix, rows, cols, argv[3]);
    delete [] matrix;
  }
  input.close();
  return 0;
}
