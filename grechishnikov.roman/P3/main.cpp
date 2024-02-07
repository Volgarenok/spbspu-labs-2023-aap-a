#include <iostream>
#include <cstddef>
#include <exception>
#include "inputStr.hpp"
#include "countUnique.hpp"

int main()
{
  using namespace grechishnikov;

  char* str = nullptr;
  try
  {
    str = inputStr(std::cin);
  }
  catch (const std::bad_alloc &e)
  {
    delete[] str;
    std::cerr << "Cannot allocate enough\n";
    return 1;
  }
  catch (const std::logic_error &e)
  {
    delete[] str;
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << countUnique(str) << "\n";
  delete[] str;
}
