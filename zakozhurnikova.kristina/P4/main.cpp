#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char * argv[])
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << "\n";
  }
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  //argv[1] - число, т.е. номер задания
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 3;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 3;
  }

  //argv[2] - имя файла с матрицей
    size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Cannot read a number\n";
      return 2;
    }
  }
}
