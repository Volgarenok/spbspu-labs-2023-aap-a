#include "removeSpaces.h"
#include <iostream>
#include <inputOperations.hpp>

int main()
{
  size_t size = 20;
  char *string = nullptr;
  char* tmp = nullptr;
  try
  {
    string = zakozhurnikova::readString(std::cin, size);
    tmp = new char[size]{};
  }
  catch (const std::exception & e)
  {
    delete[] string;
    delete[] tmp;
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  zakozhurnikova::removeSpaces(tmp, string);
  std::cout << *tmp << '\n';
  delete[] tmp;
  delete[] string;
  return 0;
}
