#include <iostream>
#include <iomanip>
#include "extendstring.h"

int main()
{
  std::cin >> std::noskipws;

  char * string = nullptr;
  size_t size = 0;
  try
  {
    size = 10;
    string = new char [10];
  }
  catch (...)
  {
    delete [] string;
    std::cerr << "Unable to allocate memory\n";
    return 1;
  }
  string = strelyaev::extendString(string, size, std::cin);
  if (string == nullptr)
  {
    std::cerr << "Unable to create a string\n";
    return 1;
  }
  std::cout << strelyaev::checkRepDgt(string) << "\n";
  delete [] string;
  std::cin >> std::skipws;
  return 0;
}
