#include <iostream>
#include <fstream>
#include <string>
#include <limits>

int min(int num1, int num2, int num3)
{
  int localMin = (num1 < num2) ? num1 : num2;
  return (localMin < num3) ? localMin : num3;
}

int min(int num1, int num2, int num3, int num4)
{
  int localMin1 = (num1 < num2) ? num1 : num2;
  int localMin2 = (num3 < num4) ? num3 : num4;
  return (localMin1 < localMin2) ? localMin1 : localMin2;
}

size_t inputArray(std::ifstream & input, int * array, size_t size, size_t sizeToRead)
{
  for (size_t i = 0; i < std::min(size, sizeToRead); ++i)
  {
    input >> array[i];
    if (!input)
    {
      return i;
    }
  }
  return std::min(size, sizeToRead);
}

void printArray(int * array, int cols, int rows)
{
  for (int i = 0; i < cols * rows; ++i)
  {
    if (i % cols == 0 and i != 0)
    {
      std::cout << "\n";
    }
    std::cout << array[i] << "\t";
  }
  std::cout << "\n";
}

size_t countOfLocalMinimums(int * array, size_t rows, size_t cols)
{
  if (rows <= 2 || cols <= 2)
  {
    return 0;
  }

  size_t result = 0;
  for (size_t idx = cols + 1; idx < (rows - 1) * cols; ++idx)
  {
    if (idx % cols != 0 && (idx + 1) % cols != 0)
    {
      int minRowUp = min(array[idx - cols - 1], array[idx - cols], array[idx - cols + 1]);
      int minRowDown = min(array[idx + cols - 1], array[idx + cols], array[idx + cols + 1]);
      if (array[idx] < min(minRowUp, minRowDown, array[idx - 1], array[idx + 1]))
      {
        size_t max_size = std::numeric_limits< size_t >::max();

        if (result == max_size)
        {
          throw std::logic_error("matrix is too long");
        }
        else
        {
          ++result;
          std::cout << idx << " " << array[idx] << "\n";
        }
      }
    }
  }

  return result;
}

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Bad input arguments\n";
    return 1;
  }

  int taskNumber = 0;
  try
  {
    taskNumber = std::stoll(argv[1]);
  }
  catch (...)
  {
    std::cerr << "Cannot parse values\n";
    return 1;
  }

  if (taskNumber == 1)
  {
    {
      std::ifstream input(argv[2]);
      size_t cols = 0;
      size_t rows = 0;

      input >> cols;
      input >> rows;
      if (!input)
      {
        std::cerr << "Cannot parse number of column or rows\n";
        return 2;
      }

      int array[cols * rows];
      int number = 0;
      for (int i = 0; i < (cols * rows); ++i)
      {
        input >> number;
        if (!input)
        {
          std::cerr << "Cannot parse number from file\n";
          return 2;
        }
        array[i] = number;
      }

      size_t result = 0;
      result = countOfLocalMinimums(array, rows, cols);

      std::cout << "CNT-LOC-MIN: " << result << "\n";
      printArray(array, cols, rows);
    }
  }
  else if (taskNumber == 2)
  {
    std::ifstream input(argv[2]);

    size_t cols = 0;
    size_t rows = 0;

    input >> cols >> rows;

    if (!input)
    {
      std::cerr << "Cannot parse number of column or rows\n";
      return 2;
    }

    int * array = new int[rows * cols];
    int number = 0;
    size_t numOfElements = 0;

    numOfElements = inputArray(input, array, (rows * cols), (rows * cols));
    if (numOfElements != (rows * cols))
    {
      std::cerr << "Cannot parse numbers from file\n";
      delete [] array;
      return 2;
    }

    size_t result = 0;
    result = countOfLocalMinimums(array, rows, cols);

    std::cout << "CNT-LOC-MIN: " << result << "\n";
    printArray(array, cols, rows);
    delete [] array;
  }
  else
  {
    std::cerr << "Cannot parse values\n";
    return 1;
  }
}
