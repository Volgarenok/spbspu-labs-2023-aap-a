#include <iostream>
#include <cstddef>
#include <stdexcept>

#include "mergeTwoLines.h"
#include "removeDuplicate.h"
#include "transformInputString.h"

int main()
{
  using namespace skuratov;
  size_t size = 10;
  char* inputLine = nullptr;
  const char* lineOfProgram = "abc";
  size_t lineSize = 3;
  try
  {
    inputLine = transformInputString(std::cin, size);

    if (inputLine[0] == '\0')
    {
      delete[] inputLine;
      throw std::invalid_argument("Empty input");
    }
    size += lineSize;

    char* result = new char[size];

    std::cout << skuratov::mergeTwoLines(result, inputLine, lineOfProgram) << '\n';
    std::cout << skuratov::removeDuplicate(result, lineOfProgram, inputLine) << '\n';
    delete[] result;
    delete[] inputLine;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}
