#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
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
    char *endPtr = nullptr;
    long long int ctrl_parameter = std::strtoll(argv[1], &endPtr, 10);
    if ((ctrl_parameter > 2 || ctrl_parameter < 1) && endPtr != argv[1])
    {
      std::cout << ctrl_parameter << "\n";
      std::cerr << "First parameter is out of range\n";
      return 1;
    }
    else if ((ctrl_parameter > 2 || ctrl_parameter < 1) && endPtr == argv[1])
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
  }
}

