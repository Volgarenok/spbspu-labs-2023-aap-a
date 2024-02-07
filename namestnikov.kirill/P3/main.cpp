#include <iostream>
#include "unique_sym_array.hpp"
#include "input_string.hpp"

int main()
{
  using namespace namestnikov;
  char * firstString = nullptr;
  size_t strIndex = 0;
  try
  {
    firstString = inputString(std::cin, strIndex);
  }
  catch (...)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  if ((firstString[0] == '\0') || (!firstString))
  {
    std::cerr << "No string input\n";
    delete [] firstString;
    return 1;
  }
  const char * secondString = "abc_ef";
  const size_t firstSize = strIndex;
  const size_t secondSize = 6;
  char * result = nullptr;
  try
  {
    result = new char[firstSize + secondSize]{};
  }
  catch (...)
  {
    delete [] firstString;
    std::cerr << "Not enough memory\n";
    return 1;
  }
  getUniqueSymArray(firstString, secondString, result);
  std::cout << result << "\n";
  delete [] firstString;
  delete [] result;
}
