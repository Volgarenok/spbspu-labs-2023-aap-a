#include <iostream>
#include <cstdlib>
#include <string>

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
}
