#include "inputString.hpp"

char* novokhatskiy::inputString(std::istream &input)
{
  size_t sizeString = 20;
  size_t cycleIndex = 0;
  char* string = nullptr;
  try
  {
    string = new char[sizeString];
  }
  catch (...)
  {
    return string;
  }
  char symbol = 0;
  input >> std::noskipws;
  while ((input >> symbol) && (symbol != '\n'))
  {
    if (cycleIndex + 1 == sizeString)
    {
      try
      {
        char* newString = new char[sizeString + 15];
        for (size_t i = 0; i < sizeString; ++i)
        {
          newString[i] = string[i];
        }
        delete[] string;
        string = newString;
        sizeString += 15;
      }
      catch (...)
      {
        delete[] string;
        throw;
      }
    }
    string[cycleIndex] = symbol;
    cycleIndex++;
  }
  string[cycleIndex] = '\0';
  input >> std::skipws;
  return string;
}
