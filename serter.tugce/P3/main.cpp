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
    buffer = new char[bufferSize]{'\0'};
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error of allocation: " << e.what() << std::endl;
    return 1;
  }

  try
  {
    serter::inputString(buffer, bufferSize);
    size_t currentIndex = 0;
    while (buffer[currentIndex] != '\0')
    {
      ++currentIndex;
    }
    if (currentIndex == bufferSize - 1)
    {
      serter::expandBuffer(buffer, bufferSize, currentIndex);
    }
    std::cout << serter::hasDuplicateCharacters(buffer) << '\n';
    delete[] buffer;
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    delete[] buffer;
    return 1;
  }
}

