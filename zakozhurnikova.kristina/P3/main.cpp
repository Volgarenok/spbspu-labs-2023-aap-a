#include <iostream>
#include "removeSpaces.h"
#include "stringOperations.h"

int main()
{
  char *buff = nullptr;
  char *dest = nullptr;
  try
  {
    size_t size = 20;
    buff = new char[size]{'\0'};
    size_t counter = 0;
    char c = '\0';
    std::cin >> std::noskipws;
    while (std::cin >> c)
    {
      if (counter == size - 1)
      {
        size *= 2;
        char *string = new char[size]{'\0'};
        zakozhurnikova::makeCopy(string, buff);
        zakozhurnikova::swapStrings(buff, string);
        delete[] string;
      }
      buff[counter] = c;
      ++counter;
      if (c == '\n')
      {
        break;
      }
    }
    if (buff[0] == '\n' || buff[0] == '\0')
    {
      std::cerr << "Empty string\n";
      delete[] buff;
      return 1;
    }

    dest = new char[size]{'\0'};
    zakozhurnikova::removeSpaces(dest, buff);
    std::cout << dest;
    std::cout << '\n';
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << '\n';
    delete[] dest;
    delete[] buff;
    return 1;
  }
  delete[] dest;
  delete[] buff;
  return 0;
}
