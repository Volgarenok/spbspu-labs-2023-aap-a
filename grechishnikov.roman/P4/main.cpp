#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

void inputArray(std::istream & in, int * a, size_t pl, size_t max)
{
  for (size_t i = 0; i < std::min(pl, max); ++i)
  {
    if(!(in >> a[i]))
    {
      throw std::logic_error("Cannot read a matrix\n");
    }
  }
}

size_t countInCol(int * a, long long rows, long long col, size_t j)
{
  size_t inCol = 1;
  size_t inColMax = 1;
  for (long long i = 0; i < rows - 1; ++i)
  {
    if (a[i*col + j] == a[(i+1)*col + j])
    {
      inCol += 1;
      inColMax = std::max(inCol, inColMax);
    }
    else
    {
      inCol = 1;
    }
  }
  return inColMax;
}

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of elements in command line arguments\n";
    return 1;
  }


  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (...)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "Wrong task number\n";
    return 1;
  }


  long long rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    input.close();
    std::cerr << "Cannot read a size of matrix\n";
    return 2;
  }
  if (rows < 0 || cols < 0)
  {
    input.close();
    std::cerr << "Wrong matrix size\n";
    return 2;
  }
  int * matr = {};
  try
  {
    if (num == 1)
    {
      matr = new int [10000];
    }
    if (num == 2)
    {
      matr = new int [rows*cols];
    }
  }
  catch (std::bad_alloc &)
  {
    input.close();
    std::cerr << "Cannot allocate memory for matrix\n";
    return 2;
  }
  try
  {
    size_t maxSize = 0;
    if (num == 1)
    {
      maxSize = 10000;
    }
    if (num == 2)
    {
      maxSize = rows * cols;
    }
    inputArray(input, matr, rows * cols, maxSize);
  }
  catch(const std::logic_error &e)
  {
    delete [] matr;
    input.close();
    std::cerr << e.what();
    return 2;
  }
  input.close();

  std::ofstream output(argv[3]);
  if (rows == 0 || cols == 0)
  {
    output << 0 << "\n";
    return 0;
  }
  size_t maxNumCol = 0;
  size_t maxPodr = 0;
  for (long long i = 0; i < cols; ++i)
  {
    if (maxPodr < countInCol(matr, rows, cols, i))
    {
      maxPodr = countInCol(matr, rows, cols, i);
      maxNumCol = i + 1;
    }
  }
  output << maxNumCol << "\n";
  output.close();
  delete [] matr;
}
