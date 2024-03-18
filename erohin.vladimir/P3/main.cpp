#include <iostream>
#include "input_string.hpp"
#include "resize_string.hpp"
#include "unite_string.hpp"
#include "replace_symbol.hpp"

int main()
{
  using namespace erohin;
  char * first = nullptr;
  const char * second = "abcdabcdabcd";
  try
  {
    first = inputString(std::cin);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Cannot allocate memory\n";
    return 1;
  }
  if (*first == '\0')
  {
    delete[] first;
    std::cerr << "Input string is null\n";
    return 2;
  }
  char * united = nullptr;
  char * replaced = nullptr;
  try
  {
    united = new char[256];
    replaced = new char[256];
  }
  catch (const std::bad_alloc &)
  {
    delete[] first;
    delete[] united;
    std::cerr << "Cannot create new strings\n";
    return 3;
  }
  united = uniteString(united, first, second);
  replaced = replaceSymbol(replaced, first, 'c', 'b');
  std::cout << united << "\n";
  std::cout << replaced << "\n";
  delete[] first;
  delete[] united;
  delete[] replaced;
  return 0;
}
