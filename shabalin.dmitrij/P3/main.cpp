#include <iostream>
#include <stdexcept>
#include "duplicateNumbers.h"
#include "inputOfString.h"
#include "makeLowerCaseString.h"

int main()
{
  char *inputString = nullptr;
  size_t stringSize = 10;
  try
  {
    inputString = shabalin::inputOfString(std::cin, stringSize);
    if (inputString[0] == '\0')
    {
      delete[] inputString;
      std::cerr << "Error" << "\n";
      return 1;
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  std::cout << shabalin::duplicateNumbers(inputString) << "\n";

  shabalin::makeLowerCaseString(inputString);
  std::cout << inputString << "\n";

  delete[] inputString;
  return 0;
}
