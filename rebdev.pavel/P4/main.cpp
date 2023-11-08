#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Incorrect number of arguments\n";
    return 1;
  }
  int arrayMode = std::stoll(argv[1]);
  if ((arrayMode != 1) && (arrayMode != 2))
  {
    std::cerr << "Incorrect first parameter\n";
    return 1;
  }

  using namespace rebdev;

  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "Cann't open " << argv[2] << '\n';
  }
  try
  {
    matrix myMatrix(arrayMode, input);
    input.close();

    std::ofstream output(argv[3]);
    if (!output.is_open())
    {
      std::cerr << "Cann't open " << argv[3] << '\n';
      return 1;
    }
    try
    {
      output << myMatrix.localMax() << '\n';
      output.close();
    }
    catch (const std::exception & e)
    {
      std::cerr << e.what();
      output.close();
      return 2;
    }

  }
  catch (const std::exception & e)
  {
    std::cerr << e.what();
    input.close();
    return 2;
  }

  return 0;
}
