#include <iostream>
#include <stdexcept>
#include "input.h"
#include "unique_symbols.h"

int main()
{
  char* string1 = nullptr;
  const char* string2 = "abc_ef";
  char* res = nullptr;
  using namespace zaitsev;
  try
  {
    string1 = readStr(std::cin);
    res = new char[256];
    uniqueChars(string1, string2, res);
  }
  catch (const std::bad_alloc&)
  {
    delete[] string1;
    delete[] res;
    std::cerr << "Failed to allocate memory" << '\n';
    return 1;
  }
  catch (const std::ios_base::failure&)
  {
    delete[] string1;
    std::cerr << "Failed to read string" << '\n';
    return 2;
  }

  std::cout << res << "\n";

  delete[] string1;
  delete[] res;
  return 0;
}
