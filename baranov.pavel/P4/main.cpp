#include <iostream>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  std::cout << argv[1] << argv[2] << argv[3] << '\n';
}
