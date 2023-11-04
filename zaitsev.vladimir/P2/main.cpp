#include <iostream>
#include <string>
#include <stdexcept>


int main(int argc, char* argv[])
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }

  int task_nmb = 1;
  try
  {
    task_nmb = std::stoi(argv[1]);
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  catch (const std::logic_error&)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if (task_nmb < 1 || task_nmb>2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  return 0;
}
