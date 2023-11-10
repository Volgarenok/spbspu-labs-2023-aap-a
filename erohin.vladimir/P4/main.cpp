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
    std::cerr << "Number is out of range\n";
    return 3;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 3;
  }
}
