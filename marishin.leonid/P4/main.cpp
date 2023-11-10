#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
  using namespace marishin;
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
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "Value out of range\n";
    return 1;
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  
}
