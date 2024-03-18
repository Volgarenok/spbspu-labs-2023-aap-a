#include "stringInput.hpp"

char * rebdev::acceptStr(std::istream & input, size_t & sizeOfStr)
{
  char sym = 0;
  sizeOfStr = 0;
  size_t sizeOfBuffer = 0;

  char * str = nullptr;
  char * str2 = nullptr;

  input >> std::noskipws;

  while (input >> sym)
  {
    if (!input)
    {
      delete[] str;
      input >> std::skipws;
      throw std::logic_error("Bad read!");
    }

    if (sizeOfStr == sizeOfBuffer)
    {
      sizeOfBuffer += 10;
      try
      {
        str2 = new char[sizeOfBuffer];
      }
      catch (const std::exception & e)
      {
        input >> std::skipws;
        delete[] str;
        delete[] str2;
        throw;
      }

      for (size_t i = 0; i < sizeOfStr; ++i)
      {
        str2[i] = str[i];
      }
      for (size_t i = sizeOfStr; i < (sizeOfBuffer * (str != nullptr)); ++i)
      {
        str2[i] = '\0';
      }

      delete[] str;
      str = str2;
      str2 = nullptr;
    }

    str[sizeOfStr] = sym;
    sizeOfStr += 1;
  }

  input >> std::skipws;
  delete[] str2;
  return str;
}
