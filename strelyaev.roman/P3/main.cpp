#include <iostream>
#include <iomanip>
#include "extendstring.h"
#include <getString.hpp>
int main()
{
  char * string = nullptr;
  std::cin >> std::noskipws;
  try
  {
    string = strelyaev::getString(std::cin);
    if (string == nullptr)
    {
      delete [] string;
      std::cerr << "Unable to create string\n";
      return 1;
    }
    if ((string[0] == '\n') || (string[0] == '\0'))
    {
      delete [] string;
      std::cerr << "Unable to create string\n";
      return 1;
    }
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
