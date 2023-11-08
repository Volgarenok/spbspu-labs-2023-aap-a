#include <iostream>
#include <fstream>
#include <string>

size_t inputArray(std::istream & in, int * a, size_t pl, size_t max)
{
  for (size_t i = 0; i < std::min(pl, max); ++i)
  {
    if(!(in >> a[i]))
    {
      return i;
    }
  }
  return std::min(pl, max);
}

int main(int argc, char ** argv)
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << "\n";
  }
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


  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a size of matrix\n";
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
    std::cerr << "Cannor allocate memory for matrix\n";
    return 2;
  }
  size_t res = inputArray(input, matr, rows * cols, rows * cols);
  if (!std::cin)
  {
    delete [] matr;
    input.close();
    return 2;
  }
  input.close();


  std::ofstream output(argv[3]);
  for(size_t i = 1; i < rows * cols + 1; ++i)
  {
    output << matr[i-1] << " ";
    if (i % cols == 0)
    {
      output << "\n";
    }
  }
  output.close();
}
