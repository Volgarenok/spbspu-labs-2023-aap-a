#include <iostream>
#include <cstddef>
#include <exception>
#include "inputStr.hpp"
#include "countUnic.hpp"

int main()
{
  using namespace grechishnikov;

  char* str = nullptr;
  size_t size = 0;
  try
  {
    str = inputStr(std::cin, size);
  }
  catch (const std::logic_error &e)
  {
    delete[] str;
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << countUnic(str, size) << "\n";
  delete[] str;
}
