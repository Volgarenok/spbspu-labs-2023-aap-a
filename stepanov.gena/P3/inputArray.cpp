#include "inputArray.hpp"
#include <iomanip>

char* stepanov::inputArray(std::istream& input, size_t& sizeString)
{
  char* string = nullptr;
  char symbol = 0;
  size_t index = 0;

  string = new char[sizeString] {};
  input >> std::noskipws;
  while (input >> symbol)
  {
    if (symbol == '\n')
    {
      break;
    }
    else if (index == sizeString - 1)
    {
      sizeString += 20;
      char* newString = nullptr;
      try
      {
        newString = new char[sizeString] {};
      }
      catch (const std::bad_alloc& e)
      {
        delete[] string;
        input >> std::skipws;
        throw;
      }
      for (size_t i = 0; i < index; i++)
      {
        newString[i] = string[i];
      }
      delete[] string;
      string = newString;
    }
    string[index++] = symbol;
  }
  input >> std::skipws;

  return string;
}

