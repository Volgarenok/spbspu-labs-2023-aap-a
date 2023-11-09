#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>


int main (int argc, char * argv[])
{
  //проверка кол-ва аргументов передаваем. при вызове программы
  if (argc != 4)
  {
    std::cerr << "Must be 3 arguments: task; name of input file; name of output file\n";
    return 1;
  }

  //проверка первого аргумента
  char * endOfParse = nullptr;
  long firstArgument = std::strtoll(argv[1],&endOfParse,10);
  if (firstArgument == 0 && endOfParse == argv[1])
  {
    std::cerr << "Cannot parse the first argument!\n";
    return 1;
  }

  if ((firstArgument < 1) || (firstArgument > 2))
  {
    std::cerr << "Number of tusk must be 1 or 2\n";
    return 1;
  }

  if (firstArgument == 1)
  {
    //файл ввода
    std::ifstream input(argv[2]);
    if (!input.is_open())
    {
      std::cerr << "Cannot open the input file\n";
      return 2;
    }

    int rows = 0;
    int cols = 0;
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "Cannot read input file\n";
      return 2;
    }

    input.close();

    //файл вывода
    std::ofstream output(argv[3]);
    if (!output.is_open())
    {
      std::cerr << "Cannot open the input file\n";
      return 2;
    }
  }

  return 0;
}
