#include <iostream>
#include "InputString.hpp"
#include "DeleteAllNumbers.hpp"
#include "CountUniqueLetters.hpp"

int main()
{
  char* string = nullptr;
  size_t sizeOfString = 50;
  char* newString = nullptr;
  try
  {
    string = vyzhanov::inputString(std::cin, sizeOfString);
    newString = new char[sizeOfString];
  }
  catch (const std::bad_alloc& e)
  {
    delete[] string;
    delete[] newString;
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  if (string[0] == '\0')
  {
    delete[] string;
    delete[] newString;
    std::cerr << "Empty string!" << "\n";
    return 1;
  }
  std::cout << vyzhanov::deleteAllNumbers(string, newString) << "\n";
  std::cout << vyzhanov::countUniqueLetters(string) << "\n";
  delete[] string;
  delete[] newString;
  return 0;
}
