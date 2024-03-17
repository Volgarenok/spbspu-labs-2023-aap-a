#include "InputString.hpp"
#include <stdexcept>

char* vyzhanov::inputString(std::istream& input, size_t& sizeOfString)
{
  size_t index = 0;
  char* string = new char[sizeOfString];
  input >> std::noskipws;
  char currentChar = 0;
  while (input >> currentChar && currentChar != '\n')
  {
    string[index] = currentChar;
    if (index + 1 == sizeOfString)
    {
      try
      {
        char* newString = new char[sizeOfString + 10];
        for (size_t i = 0; i < sizeOfString; ++i)
        {
          newString[i] = string[i];
        }
        delete[] string;
        string = newString;
        sizeOfString += 5;
      }
      catch (const std::bad_alloc &e)
      {
        input >> std::skipws;
        delete[] string;
        throw;
      }
    }
    index++;
  }
  string[index] = '\0';
  input >> std::skipws;
  return string;
}
