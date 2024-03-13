#include "streamtostring.hpp"
#include "substractstring.hpp"
#include "removespaces.hpp"
#include <cstddef>

int main()
{
  char *firstString = nullptr;
  char *cloneString = nullptr;
  char *secondString = nullptr;
  size_t length = 0;

  try
  {
    firstString = petuhov::streamToString(std::cin);
  }
  catch (std::exception &e)
  {
    std::cerr << e.what();
    return 1;
  }
  if (firstString != nullptr)
  {
    while (firstString[length] != '\0')
    {
      ++length;
    }
    try
    {
      cloneString = new char[length + 1];
    }
    catch (std::exception &e)
    {
      delete[] firstString;
      std::cerr << "Error while creating cloneString";
      return 1;
    }
  }
  try
  {
    secondString = petuhov::streamToString(std::cin);
  }
  catch (std::exception &e)
  {
    delete[] firstString;
    std::cerr << e.what();
    return 1;
  }

  petuhov::removeSpaces(firstString, cloneString);
  petuhov::substractString(firstString, secondString);
  if (!firstString)
  {
    std::cerr << "first string is empty";
    return 2;
  }
  std::cout << firstString << "\n" << cloneString << "\n";
  delete[] firstString;
  delete[] cloneString;
  delete[] secondString;
  return 0;
}
