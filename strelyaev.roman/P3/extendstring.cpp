#include "extendstring.h"

char * strelyaev::extendString(char * string, size_t size, std::istream & in)
{
    size_t buffer_size = size;
    char c = 0;
    size_t i = 0;
    while ((in >> c) && (c != '\n'))
    {
      if (!in)
      {
        return nullptr;
      }
      string[i++] = c;
      if (i == (size - 1))
      {
        buffer_size += 10;
        char * buffer = nullptr;
        buffer = new char [buffer_size];
        for (size_t j = 0; j < i; j++)
        {
          buffer[j] = string[j];
        }
        delete [] string;
        string = buffer;
        size = buffer_size;
      }
    }
    string[i] = '\0';
    if ((string[0] == '\n') || (string[0] == '\0'))
    {
      delete [] string;
      return nullptr;
    }
    return string;
}

int strelyaev::checkRepDgt(char * const string)
{
  size_t i = 0;
  for (i = 0; string[i] != '\0'; i++)
  {
    if (std::isdigit(string[i]))
    {
      for (size_t j = 0; string[j] != '\0'; j++)
      {
        if ((string[i] == string[j]) && (i != j))
        {
          return 1;
        }
      }
    }
  }
  return 0;
}
