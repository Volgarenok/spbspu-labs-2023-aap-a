#include <iostream>
#include <string>
int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of line arguments\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoi(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "First argument is not a number\n";
    return 1;
  }
  if (num > 2)
  {
    std::cerr << "Wrong task number\n";
    return 1;
  }
  if (num == 1) //handling using static array
  {
    return 0;
  }
  else if (num == 2) //handling ising dynamic array
  {
    return 0;
  }
}
