#include <iostream>
#include "extractChars.hpp"
#include "addLat.hpp"
#include "inputString.hpp"

int main()
{
  using namespace isaychev;
  size_t capacity = 10, length1 = 0;
  size_t & linkToCap = capacity;
  size_t & linkToLgth = length1;
  char * str = nullptr;
  try
  {
    str = inputString(std::cin, linkToLgth, linkToCap);
  }
  catch (const char * errMessage)
  {
    std::cerr << errMessage << "\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
  const char * str2 = "AFD12hd";
  size_t length2 = 0;
  while (str2[length2] != '\0')
  {
    length2++;
  }
  char * str_after_extr = nullptr;
  char * strLat = nullptr;
  try
  {
    size_t size = 'z' - 'a' + 1;
    str_after_extr = new char[capacity]{};
    strLat = new char[size + 1]{};
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for two final strings\n";
    delete [] str_after_extr;
    delete [] strLat;
    delete [] str;
    return 1;
  }
  extractChars(str, str2, str_after_extr);
  addLat(str, str2, strLat);
  std::cout << str_after_extr << "\n" << strLat << "\n";
  delete [] str_after_extr;
  delete [] strLat;
  delete [] str;
}
