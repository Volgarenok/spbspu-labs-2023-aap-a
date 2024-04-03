#include <iomanip>
#include <exception>
#include <iostream>
#include "removeDigits.hpp"
#include "removeLetters.hpp"
#include "inputString.hpp"

int main()
{
  std::cin >> std::noskipws;
  char * array = nullptr;
  char * rezult = nullptr;
  int size = 1000;
  try
  {
    array = vojuck::inputString(std::cin);
    rezult = new char[size]{};
    if ( array == nullptr)
    {
      std::cerr << "no input";
      return 1;
    }
    if (array[0] == '\0' || array[0] == '\n')
    {
      std::cerr << "no input (" << "\n";
      return 1;
    }
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  if (array != nullptr)
  {
    vojuck::removeDigits(array,rezult);
    std::cout << rezult << "\n";
    vojuck::removeLetters(array,rezult);
    std::cout << rezult << "\n";
  }
  std::cin >> std::skipws;
  delete [] array;
  delete [] rezult;
}

