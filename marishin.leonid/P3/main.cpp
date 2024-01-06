#include <iostream>

#include "inputstring.hpp"
#include "modifystring.hpp"

int main()
{
  using namespace marishin;
  std::cin >> std::noskipws;
  char targetChar = 0;
  char replacementChar = 0;
  char* buffer = nullptr;
  char* result = nullptr;
  try
  {
    buffer = inputString(std::cin);
  }
  catch (const std::exception& ba)
  {
    std::cerr << "Error: " << ba.what() << '\n';
    return 1;
  }
  std::cin >> std::skipws;
  std::cin >> targetChar >> replacementChar;
  try
  {
    result = modifyString(buffer, targetChar, replacementChar);
  }
  catch (const std::exception& ba)
  {
    std::cerr << "Error: " << ba.what() << '\n';
    return 1;
  }
  std::cout << result;
  delete[] buffer;
  delete[] result;
}
