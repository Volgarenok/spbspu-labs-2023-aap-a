#include <iostream>
#include <fstream>
#include <string>
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

  //argv[1] - number
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 3;
  }
  std::cout << "Num: " << num << "\n";

  //argv[2] - file
  int i = 0;
  {
    std::ifstream input(argv[2]);
    input >> i;
    if (!input)
    {
      std::cerr << "Cannot read a numder\n";
      return 2;
    }
  }

  std::cout << i << "\n";

  //argc[3] - file
  std::ofstream output(argv[3]);
  output << i << "\n";
}
