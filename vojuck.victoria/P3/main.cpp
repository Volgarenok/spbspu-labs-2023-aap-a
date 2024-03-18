#include <iomanip>
#include "removeDigits.hpp"
#include "removeLetters.hpp"
#include "inputString.hpp"

int main()
{
  std::cin >> std::noskipws;
  int size = 20;
  char * array = nullptr;
  try
  {
    array = vojuck::inputString(std::cin, size);
    char * resultDigits = new char[size]{};
    vojuck::removeDigits(array, resultDigits);
    char * resultLetters = new char[size]{};
    vojuck::removeLetters(array, resultLetters);
    std::cout << resultDigits << "\n" << resultLetters << "\n";
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  std::cin >> std::skipws;

}

