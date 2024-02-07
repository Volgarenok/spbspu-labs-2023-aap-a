#include <iostream>
#include <cstddef>
#include <cstring>
#include "stringInput.hpp"
#include "stringConvert.hpp"


int main()
{
  char * firstStr = nullptr;
  size_t firstSize = 0;
  try
  {
    firstStr = rebdev::acceptStr(std::cin, firstSize);
  }
  catch (const std::exception & e)
  {
    delete[] firstStr;
    std::cerr << e.what() << '\n';
    return 1;
  }
  if (firstStr == nullptr)
  {
    delete[] firstStr;
    std::cerr << "String is empty\n";
    return 1;
  }

  char const * const secondStr = "1 2ok 3 5z 3pv21";

  size_t numOfDig = 0;
  for (size_t i = 0; secondStr[i] != '\0'; ++i)
  {
    if (std::isdigit(secondStr[i]))
    {
      numOfDig += 1;
    }
  }

  char * finishStr = nullptr;
  try
  {
    finishStr = new char[firstSize + numOfDig + 1];
    for (size_t i = 0; i < (firstSize + numOfDig); ++i)
    {
      finishStr[i] = '0';
    }
    finishStr[firstSize + numOfDig] = '\0';
  }
  catch (const std::exception & e)
  {
    return 2;
  }

  rebdev::addNumbers(firstStr, secondStr, finishStr);

  std::cout << finishStr << '\n';
  delete[] finishStr;
  delete[] firstStr;

  return 0;
}
