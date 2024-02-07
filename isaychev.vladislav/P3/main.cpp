#include <iostream>
#include "extractChars.hpp"
#include "addLat.hpp"
#include "inputString.hpp"

int main()
{
  using namespace isaychev;
  size_t capacity = 10, length1 = 0;
  char * str = nullptr;
  try
  {
    str = inputString(std::cin, length1, capacity);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for first string\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
  const char * str2 = "AFD12hd";
  char * strAfterExtr = nullptr;
  char * strLat = nullptr;
  try
  {
    size_t size = 'z' - 'a' + 1;
    strAfterExtr = new char[capacity]{};
    strLat = new char[size + 1]{};
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for two final strings\n";
    delete [] strAfterExtr;
    delete [] strLat;
    delete [] str;
    return 1;
  }
  extractChars(str, str2, strAfterExtr);
  addLat(str, str2, strLat);
  std::cout << strAfterExtr << "\n" << strLat << "\n";
  delete [] strAfterExtr;
  delete [] strLat;
  delete [] str;
}
