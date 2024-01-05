#include "stringInput.hpp"

char * rebdev::acceptStr(std::istream & input, size_t & sizeOfStr)
{
  char sym = 0;
  sizeOfStr = 1;

  char * str = nullptr;
  char * str2 = nullptr;

  input >> std::noskipws;

  while (input >> sym)
  {
    if(!input)
    {
      delete[] str;
      input >> std::skipws;
      throw std::logic_error("Bad read!");
    }

    try
    {
      str2 = new char[sizeOfStr + 1];
    }
    catch (const std::exception & e)
    {
      input >> std::skipws;
      delete[] str;
      delete[] str2;
      throw;
    }
    for (size_t i = 0; i < (sizeOfStr * (str != nullptr)); ++i)
    {
      str2[i] = str[i];
    }

    delete[] str;
    str = str2;
    str2 = nullptr;

    str[sizeOfStr - 1] = sym;
    str[sizeOfStr] = '\0';

    sizeOfStr += 1;
  }

  input >> std::skipws;
  delete[] str2;
  return str;
}
