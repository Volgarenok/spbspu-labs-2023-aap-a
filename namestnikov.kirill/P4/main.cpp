#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

void freeMatrix(int ** m, size_t rows, size_t cols)
{
  if (m == nullptr)
  {
    return;
  }
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
    rowsptrs[i] = nullptr;
  }
  try
  {
    for (size_t i = 0; i < rows; ++i)
    {
      rowsptrs[i] = new int[cols];
    }
    return rowsptrs;
  }
  catch (const std::bad_alloc &)
  {
    freeMatrix(rowsptrs, rows, cols);
    throw;
  }
}

size_t inputArray(std::istream & in, int * a, size_t s, size_t toread)
{
  for (size_t i = 0; i < std::min(toread, s); ++i)
  {
    if (!(in >> a[i]))
    {
      return i;
    }
  }
  return std::min(toread, s);
}

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
    if ((num != 1) && (num != 2))
    {
      std::cerr << "Wrong number in command line\n";
      return 3;
    }

  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 3;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 3;
  }
  if (num == 1)
  {
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Can not read a number\n";
      return 2;
    }
    int matrix[10000];
    for (int i = 0; i < rows * cols; ++i)
    {
      input >> matrix[i];
      if (!input)
      {
        std::cerr << "Can not read a number\n";
        return 2;
      }
    }
    std::ofstream output(argv[3]);
    int minRow[10000];
    int maxCol[10000];
    for (int i = 0; i < rows * cols; i = i + cols)
    {
      minRow[i] = matrix[i];
      for (int j = 0; j < cols; ++j)
      {
        if (matrix[i + j] < minRow[i])
        {
          minRow[i] = matrix[i + j];
        }
      }
    }
    for (int j = 0; j < cols; ++j)
    {
      maxCol[j] = matrix[j];
      for (int i = 0; i < rows * cols; i = i + cols)
      {
        if (matrix[j + i] > maxCol[j])
        {
          maxCol[j] = matrix[j + i];
        }
      }
    }
    size_t count = 0;
    for (int i = 0; i < rows * cols; i = i + cols)
    {
      for (int j = 0; j < cols; ++j)
      {
        if ((matrix[i+j] == minRow[i]) && (matrix[i+j] == maxCol[j]))
        {
          ++count;
        }
      }
    }
    output << count << "\n";
  }
  else if (num == 2)
  {
    int rows = 0;
    int cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Can not read\n";
      return 2;
    }
    int **matrix = nullptr;
    try
    {
      matrix = createMatrix(rows, cols);
      size_t result = inputArray(input, *matrix, rows * cols, rows * cols);
      int minRow[10000];
      int maxCol[10000];
      for (int i = 0; i < rows; ++i)
      {
        minRow[i] = matrix[i][0];
        for (int j = 0; j < cols; ++j)
        {
          if (matrix[i][j] < minRow[i])
          {
            minRow[i] = matrix[i][j];
          }
        }
      }
      for (int j = 0; j < cols; ++j)
      {
        maxCol[j] = matrix[0][j];
        for (int i = 0; i < rows; ++i)
        {
          if (matrix[i][j] > maxCol[j])
          {
            maxCol[j] = matrix[i][j];
          }
        }
      }
      size_t count = 0;
      for (int i = 0; i < rows; ++i)
      {
        for (int j = 0; j < cols; ++j)
        {
          if ((matrix[i][j] == maxCol[j]) && (matrix[i][j] == minRow[i]))
          {
            ++count;
          }
        }
      }
      std::ofstream output(argv[3]);
      output << count << "\n";
      freeMatrix(matrix, rows, cols);
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Not enough memory\n";
      return 4;
    }
  }
}
