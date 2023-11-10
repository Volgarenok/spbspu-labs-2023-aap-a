#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  unsigned char task = 0;
  try
  {
    task = std::stoll(argv[1]);
  }
  catch (...)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  if (task != 1 && task != 2)
  {
    std::cerr << "Incorrect task number\n";
    return 1;
  }

  unsigned int rows = 0;
  unsigned int columns = 0;
  {
    std::fstream input(argv[2]);
    input >> rows >> columns;
    if (!input)
    {
      std::cerr << "Incorrect parametrs for matrix\n";
      return 2;
    }
  }
}
