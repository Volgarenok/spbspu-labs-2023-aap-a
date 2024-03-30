#include <iostream>
#include <exception>
#include "inputString.hpp"
#include "removing_spaces.hpp"
#include "copyNum.hpp"
#include "removing_vowels.hpp"

int main()
{
  using namespace sivkov;
  char* inputString = nullptr;
  char inputString2[13] = { "h3ll0 w0r1d!" };
  try
  {
    inputString = addString(std::cin);
  }
  catch (...)
  {
    std::cerr << "Memory allocation failed\n";
    return 1;
  }
  if ((inputString[0] == '\0') || (!inputString))
  {
    std::cerr << "Mo input\n";
    delete[] inputString;
    return 1;
  }

  deleteSpace(inputString);
  std::cout << "\n[SPC-RMV]: " << inputString << '\n';
  copyNum(inputString, inputString2);
  std::cout << "[DGT-SND]: " << inputString << '\n';
  removing_vowels(inputString);
  std::cout << "[RMV-VOW]: " << inputString << '\n';

  delete[] inputString;
  return 0;
}
