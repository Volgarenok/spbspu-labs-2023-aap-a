#include <iostream>
#include <cstdlib>
#include <fstream>

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
  int n = 0;
  int m = 0;
  std::ifstream input(argv[2]);
  input >> n;
  input >> m;
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
  for (int i = 0; i < m * n; ++i)
  {
    output << a[i];
  }
}
