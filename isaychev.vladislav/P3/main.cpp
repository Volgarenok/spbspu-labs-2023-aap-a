#include <iostream>
#include <inputString.hpp>
#include "extractChars.hpp"
#include "addLat.hpp"

int main()
{
  using namespace isaychev;
  size_t capacity = 10;
  char * str = nullptr;
  try
  {
    str = inputString(std::cin, capacity);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for first string\n";
    return 1;
  }
  if (checkForEmptyStr(str))
  {
    delete [] str;
    std::cerr << "String is empty\n";
    return 3;
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
