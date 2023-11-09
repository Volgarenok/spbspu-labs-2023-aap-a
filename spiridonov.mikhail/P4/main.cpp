#include <iostream>
#include <fstream>
#include <stdexcept>


int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Usage: ./lab num input output" << "\n";
    return 1;
  }

  int num = std::atoi(argv[1]);
  std::ifstream input(argv[2]);

  if (!input)
  {
    std::cout << "Failed to open input file: " << argv[2] << "\n";
    return 2;
  }
  int rows = 0;
  int cols = 0;
  input >> rows >> cols;

  num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << "Error parsing first argument" << "\n";
    return 1;
  }

  if ((num < 1) || (num > 2))
  {
    std::cerr << "First argument must be 1 or 2" << "\n";
    return 1;
  }
  return 0;
}
