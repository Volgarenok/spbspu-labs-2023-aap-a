#include <iostream>
#include <cstdlib>
#include <fstream>

int main(int argc, char * argv[])
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  else if (argc == 4)
  {
    char * endPtr = nullptr;
    long long int ctrl_parameter = std::strtoll(argv[1], &endPtr, 10);
    if ((ctrl_parameter > 2 || ctrl_parameter < 1) && endPtr != argv[1])
    {
      std::cerr << "First parameter is out of range\n";
      return 1;
    }
    else if ((ctrl_parameter > 2 || ctrl_parameter < 1) && endPtr == argv[1])
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
    else if (ctrl_parameter == 1 || ctrl_parameter == 2)
    {
      // starting input
      unsigned long long int rows = 0;
      {
        std::ifstream input(argv[2]);
        input >> rows;
        if (!input)
        {
          std::cerr << "Number of rows in array must be described as positive integer number\n";
          return 2;
        }
      }
      {
        std::ofstream output(argv[3]);
        output << rows << "\n";
      }
    }
  }
}
