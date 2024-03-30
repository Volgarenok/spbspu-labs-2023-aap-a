#include "inputString.hpp"
#include <iostream>
#include <stdexcept>

bool isaychev::checkForEmptyStr(const char * str)
{
  if (str[0] == '\0')
  {
    return true;
  }
  return false;
}

void copyString(const char * str, char * str2)
{
  for (size_t j = 0; str[j] != '\0'; ++j)
  {
    str2[j] = str[j];
  }
}

char * isaychev::inputString(std::istream & input, size_t & capacity)
{
  size_t length = 0;
  char * str = nullptr;
  try
  {
    str = new char[capacity]{};
    char curr_char = 0;
    input >> std::noskipws;
    while ((input >> curr_char) && (length < capacity))
    {
      if (length == capacity - 1)
      {
        capacity += 10;
        char * bigger_str = new char[capacity]{};
        copyString(str, bigger_str);
        delete [] str;
        str = bigger_str;
      }
      str[length] = curr_char;
      if (curr_char == '\n')
      {
        str[length] = '\0';
        break;
      }
      if (input.eof())
      {
        delete [] str;
        break;
      }
      length++;
    }
  }
  catch (const std::bad_alloc &)
  {
    delete [] str;
    throw;
  }
  input >> std::skipws;
  return str;
}
