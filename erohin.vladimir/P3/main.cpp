#include <iostream>
#include "input_string.hpp"
#include "lengthen_string.hpp"
#include "unite_string.hpp"
#include "replace_symbol.hpp"

int main()
{
  using namespace erohin;
  char* first = nullptr;
  const char* second = "abcdabcdabcdabcd";
  char old = 'c';
  char change = 'b';
  try
  {
    first = inputString(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    delete[] first;
    std::cerr << "Cannot allocate memory: " << e.what() << "\n";
    return 1;
  }
  if (first[0] == '\0')
  {
    std::cerr << "String is null\n";
    delete[] first;
    return 2;
  }
  char* united = uniteString(first, second);
  char* replaced = replaceSymbol(first, old, change);
  if (!united || !replaced)
  {
    std::cerr << "Invalid string creation\n";
    delete[] first;
    delete[] united;
    delete[] replaced;
    return 3;
  }
  std::cout << united << "\n";
  std::cout << replaced << "\n";
  delete[] first;
  delete[] united;
  delete[] replaced;
  return 0;
}
