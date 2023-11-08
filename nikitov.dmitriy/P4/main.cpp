#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Wrong command line input\n";
    return 1;
  }

  int type = 0;
  try
  {
    type = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Error: First argument is out of range\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Error: First argument is not a number\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Error: Can't read numbers of rows and columns in file\n";
      return 2;
    }
  }

  if (type == 1)
  {
    int matrix[10000];
    for (int i = 0; i != rows * cols; ++i)
    {
      input >> matrix[i];
    }
    if (!input)
    {
      std::cerr << "Error: Wrong input\n";
      return 1;
    }
  }
  else if (type == 2)
  {
    std::cout << "Dynamic\n";
  }
  else
  {
    std::cerr << "Error: First number doesn't match\n";
    return 1;
  }

  std::ofstream output(argv[3]);
  output << rows << cols << '\n';
  return 0;
}
