#include "inputline.hpp"

char * piyavkin::inputLine(std::istream & in)
{
  size_t length = 0;
  char sym = 0;
  char * old_line = nullptr;
  char * new_line = nullptr;
  while (in >> sym)
  {
    old_line = new_line;
    new_line = new char[length + 2] {};
    for (size_t i = 0; i < length; ++i)
    {
      new_line[i] = old_line[i];
    }
    delete [] old_line;
    new_line[length++] = std::tolower(sym);
    if (sym == '\n')
    {
      new_line[length - 1] = '\0';
      break;
    }
    new_line[length] = '\0';
  }
  if (new_line == nullptr)
  {
    throw std::logic_error("Line not read");
  }
  return new_line;
}
