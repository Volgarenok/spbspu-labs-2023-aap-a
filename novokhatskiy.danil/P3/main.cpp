#include <iostream>
#include <stdexcept>
#include "deleteLatinLetters.hpp"
#include "inputString.hpp"

int main()
{
  using namespace novokhatskiy;
  char* buffer = nullptr;
  try
  {
    buffer = inputString(std::cin);
    if (!buffer)
    {
      std::cerr << "Can't read the string\n";
      return 1;
    }
    if (buffer[0] == '\0')
    {
      std::cerr << "Wrong input\n";
      delete[] buffer;
      return 1;
    }
    buffer = deleteLatinLetters(buffer, buffer);
    std::cout << buffer << "\n";
    delete[] buffer;
  }
  catch (...)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  return 0;
}

