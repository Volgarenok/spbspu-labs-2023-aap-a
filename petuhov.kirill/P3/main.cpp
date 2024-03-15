#include <cstddef>
#include "streamtostring.hpp"
#include "substractstring.hpp"
#include "removespaces.hpp"

int main()
{
  char *firstString = nullptr;
  char *cloneString = nullptr;
  char *secondString = nullptr;
  size_t length = 0;

  try
  {
    firstString = petuhov::streamToString(std::cin);
    if (firstString != nullptr)
    {
      while (firstString[length] != '\0')
      {
        ++length;
      }
      cloneString = new char[length + 1];
    }
    secondString = petuhov::streamToString(std::cin);

    petuhov::removeSpaces(firstString, cloneString);
    petuhov::substractString(firstString, secondString);
    if (!firstString)
    {
      delete[] firstString;
      std::cerr << "first string is empty";
      return 2;
    }
    std::cout << firstString << "\n" << cloneString << "\n";
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what();
    delete[] firstString;
    delete[] cloneString;
    delete[] secondString;
    return 1;
  }

  delete[] firstString;
  delete[] cloneString;
  delete[] secondString;
  return 0;
}
