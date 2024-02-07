#include <iostream>
#include <iomanip>
#include "extendstring.h"

int main()
{
  char * string = nullptr;
  std::cin >> std::noskipws;
  try
  {
    string = strelyaev::inputString(std::cin);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << strelyaev::checkRepDgt(string) << "\n";
  delete [] string;
  std::cin >> std::skipws;
  return 0;
}
