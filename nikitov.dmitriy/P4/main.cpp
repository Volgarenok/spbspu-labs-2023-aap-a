#include <iostream>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Wrong command line input\n";
    return 1;
  }
  int type = 0;
  try
  {
    type = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Error: First argument is out of range\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Error: First argument is not a number\n";
    return 1;
  }
  if (type == 1)
  {
    std::cout << "Static\n";
    return 0;
  }
  else if (type == 2)
  {
    std::cout << "Dynamic\n";
    return 0;
  }
  else
  {
    std::cerr << "Error: First number doesn't match\n";
    return 1;
  }
}
