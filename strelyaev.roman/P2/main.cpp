#include <iostream>
#include <fstream>

int main(int argc, char * argv[])
{
  std::fstream input(argv[2]);
  std::fstream output(argv[3]);
  int i = 0;
  input >> i;
  if (!input)
  {
    std::cerr << "CANNOT READ A NUMBER\n";
    return 2;
  }

  output << i;

}
