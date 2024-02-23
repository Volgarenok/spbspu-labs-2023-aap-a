#include <iostream>

#include "read_string.h"
#include "convert_to_lowercase.h"
#include "strings_merge.h"

int main()
{
  const size_t defaultSize = 1000;

  char * firstString = nullptr;
  char * secondString = nullptr;
  char * result = nullptr;
  try
  {
    firstString = kovtun::readString(std::cin);
    secondString = kovtun::readString(std::cin);

    if (firstString[0] == '\0' && secondString[0] == '\0')
    {
      delete [] firstString;
      delete [] secondString;
      std::cerr << "empty input\n";
      return 2;
    }

    result = new char[defaultSize]();
    kovtun::convertToLowercase(result, firstString);
    std::cout << result << '\n';

    result = kovtun::mergeStrings(result, firstString, secondString);
    std::cout << result << '\n';
  }
  catch (...)
  {
    delete [] firstString;
    delete [] secondString;
    delete [] result;

    std::cerr << "unexpected error occurred\n";
    return 1;
  }

  delete [] firstString;
  delete [] secondString;
  delete [] result;

  return 0;
}

