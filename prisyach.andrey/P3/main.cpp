#include <iostream>
#include <stdexcept>
#include "ioString.hpp"
#include "tasks.hpp"

int main()
{
  char* inputString = nullptr;
  const char str[] = "abc";
  size_t size = 0;
  try
  {
    inputString = prisyach::inputTheString(std::cin, size);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  std::cout << prisyach::isDuplicateCharacters(inputString, size) << '\n';
  inputString = prisyach::mergeStrings(inputString, str, size);
  prisyach::outputTheString(inputString, size);
  delete[] inputString;
  return 0;
}
