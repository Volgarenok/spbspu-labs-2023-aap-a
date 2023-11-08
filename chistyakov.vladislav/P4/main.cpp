#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Bad input arguments\n";
    return 1;
  }

  int taskNumber = std::stoll(argv[1]);
  if (taskNumber == 1)
  {
    {
      std::ifstream input(argv[2]);
      while (!input.eof())
      {
        int i = 0;
        input >> i;
        std::cout << i << "\n";
      }
    }
  }
}
