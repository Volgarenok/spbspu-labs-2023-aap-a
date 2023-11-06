#include <iostream>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Bad arguments";
    return 1;
  }
  
  int num = 0;
  try
  {
    num = std::stoi(argv[1]);
  }
  catch (const std::exception &e)
  {
    std::cerr << "Invalid argument of task number\n";
    return 1;
  }

  if (num != 1 && num != 2)
  {
    std::cerr << "Invalid argument of task number\n";
    return 1;
  }
  return 0;
}
