#include <iostream>
#include <cstdlib>
#include <fstream>

size_t InputArray(std::istream & in, int * a, size_t s, size_t toread)
{
  for (size_t i = 0; i < std::min(toread, s); ++ i)
  {
    if (!(in >> a[i]))
    {
      return i;
    }
  }
  return std::min(toread, s);
}

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Arguments entered incorrectly\n";
    return 1;
  }
  try
  {
    int num = std::stoll(argv[1]);
      if (num != 1 && num != 2)
      {
        std::cerr << "The first parameter is incorrectly specified\n";
        return 3;
      }
  }
  catch (...)
  {
    std::cerr << "The first parameter is incorrectly specified\n";
    return 3;
  }
  int num = std::stoll(argv[1]);
  if (num == 1)
  {
    int n = 0;
    int m = 0;
    bool flag = true;
    std::ifstream input(argv[2]);
    input >> n >> m;
    int a[10000];
    for (int i = 0; i < n * m; ++i)
    {
      input >> a[i];
    }
    if (!input)
    {
      std::cerr << "Can not read number\n";
      return 2;
    }
    std::ofstream output(argv[3]);
    if (n == m && n > 1)
    {
      for (int i = 0; i < n * m; ++i)
      {
        if (i > ((i / m) * (m + 1) + 1) && a[i] != 0)
        {
          flag = false;
          break;
        }
      }
    }
    else
    {
      flag = false;
    }
    output << flag << "\n";
  }
  if (num == 2)
  {
  int n = 0;
  int m = 0;
  std::ifstream input(argv[2]);
  input >> n >> m;
  int * matrix = new int [n*m];
  size_t result = InputArray(input, matrix, n * m, n * m);
  if (!input)
  {
    std::cerr << "Can not read\n";
    delete [] matrix;
    return 2;
  }
  std::ofstream output(argv[3]);
  output << result;
  }
}
