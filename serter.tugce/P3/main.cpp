#include "input.hpp"
#include "hasDuplicateCharacters.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  size_t bufferSize = 20;
  char* buffer = nullptr;

  try
  {
    buffer = serter::inputString(std::cin, bufferSize);
    serter::checkForEmptyString(buffer, bufferSize);
    std::cout << serter::hasDuplicateCharacters(buffer, bufferSize) << '\n';
    delete[] buffer;
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    delete[] buffer;
    return 1;
  }
  return 0;
}

