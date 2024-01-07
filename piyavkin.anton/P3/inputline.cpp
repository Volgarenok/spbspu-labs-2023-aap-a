#include <istream>
#include <iostream>
#include "inputline.hpp"

char * piyavkin::inputLine(std::istream & in, size_t & length)
{
  char sym = 0;
  char * old_line = nullptr;
  char * new_line = nullptr;
  while (in >> sym)
  {
    old_line = new_line;
    new_line = new char [length + 1] {};
    for (size_t i = 0; i < length; ++i)
    {
      new_line[i] = old_line[i];
    }
    delete[] old_line;
    new_line[length++] = tolower(sym);
    if (sym == '\n')
    {
      new_line[length-1] = '\0';
      break;
    }
  }
  return new_line;
}

