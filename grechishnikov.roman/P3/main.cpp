#include <iostream>
#include <cstddef>
#include <exception>
#include <inputString.hpp>
#include "countUnique.hpp"

int main()
{
  using namespace grechishnikov;

  const char* str = nullptr;
  try
  {
    str = inputString(std::cin);
  }
  catch (const std::bad_alloc &e)
  {
    delete[] str;
    std::cerr << "Cannot allocate enough memory\n";
    return 1;
  }
  if (str == nullptr)
  {
    std::cerr << "String is empty\n";
    return 2;
  }
  std::cout << countUnique(str) << "\n";
  delete[] str;
}
