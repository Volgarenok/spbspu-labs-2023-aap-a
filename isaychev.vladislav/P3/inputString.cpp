#include "inputString.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>

char * isaychev::inputString(std::istream & input, size_t & length1, size_t & capacity)
{
  char * str = nullptr;
  str = new char[capacity]{};
  if (str == nullptr)
  {
    throw "can't allocate memory for string";
  }
  char curr_char = 0;
  input >> std::noskipws;
  while ((input >> curr_char) && (length1 < capacity))
  {
    if (length1 == capacity - 1)
    {
      capacity += 10;
      char * bigger_str = nullptr;
      bigger_str = new char[capacity]{};
      if (bigger_str == nullptr)
      {
        delete [] str;
        throw "can't allocate memory for string";
      }
      copyString(str, bigger_str, length1);
      delete [] str;
      str = bigger_str;
    }
    str[length1] = curr_char;
    if (curr_char == '\n')
    {
      str[length1] = '\0';
      break;
    }
    length1++;
  }
  if (length1 == 0)
  {
    delete [] str;
    throw std::logic_error("Not enough characters in string");
  }
  input >> std::skipws;
  return str;
}

void isaychev::copyString(const char * str, char * str2, size_t len)
{
  for (size_t j = 0; j < len; ++j)
  {
    str2[j] = str[j];
  }
}
