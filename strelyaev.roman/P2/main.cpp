#include <iostream>
#include <fstream>



int main(int argc, char * argv[])
{
  std::fstream input(argv[2]);
  std::fstream output(argv[3]);
  size_t rows = 0;
  size_t columns = 0;

  try
  {
    int n = std::stoll(argv[1]);
  }
  catch(const std::invalid_argument &)
  {
    std::cerr << "UNABLE TO PARSE FIRST ARGUMENT";
  }

  input >> rows;
  input >> columns;
  if (!input)
  {
    std::cerr << "CANNOT READ A NUMBER\n";
    return 2;
  }
}
