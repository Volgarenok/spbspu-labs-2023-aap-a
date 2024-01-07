#include "seqsym.hpp"
#include "inputArray.hpp"
#include <iostream>

int main()
{
  char* currentArray = nullptr;
  size_t size = 10;

  try
  {
    currentArray = spiridonov::inputArray(std::cin, size);
    int result = spiridonov::hasConsecutiveDuplicates(currentArray);
    std::cout << result << '\n';
  }
  catch (...)
  {
    std::cerr << "Failed work " << "\n";
    delete[] currentArray;
    return 1;
  }

  delete[] currentArray;

  return 0;
}
