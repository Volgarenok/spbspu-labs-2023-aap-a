#include <iomanip>
#include "removeDigits.hpp"
#include "removeLetters.hpp"
#include "inputString.hpp"

using namespace vojuck;

int main()
{
  int size = 20;
  char * array = new char[size]{};
  std::cin >> std::noskipws;
  try
  {
    inputString(std::cin, array, size);
    char * resultDigits = new char[size]{};
    removeDigits(array, resultDigits);
    char * resultLetters = new char[size]{};
    removeLetters(array, resultLetters);
    std::cout << resultDigits << "\n" << resultLetters << "\n";
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  std::cin >> std::skipws;

}

