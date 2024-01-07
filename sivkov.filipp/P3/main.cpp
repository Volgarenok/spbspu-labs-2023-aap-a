#include <iostream>
#include "removing_spaces.hpp"
#include "copyNum.hpp"
#include "inputString.hpp"

int main()
{
  using namespace sivkov;
  size_t size = 20;
  char* string = addString(size);
  if (!string || string == nullptr)
  {
    std::cerr << "Error with array\n";
    delete[] string;
    return 1;
  }

  string = deleteSpace(string);
  std::cout << string << "\n";
  delete[] string;

  char* string1 = addString(size);
  if (!string1 || string1 == nullptr)
  {
    std::cerr << "Error with array\n";
    delete[] string1;
    return 1;
  }
  char* string2 = addString(size);
  if (!string2 || string2 == nullptr)
  {
    std::cerr << "Error with array\n";
    delete[] string1;
    delete[] string2;
    return 1;
  }
  string = copyNum(string1, string2);
  if (string == nullptr)
  {
    std::cerr << "Error with array\n";
    delete[] string;
    delete[] string1;
    delete[] string2;
    return 1;
  }
  std::cout << string << "\n";
  delete[] string;
  delete[] string1;
  delete[] string2;

  return 0;
}
