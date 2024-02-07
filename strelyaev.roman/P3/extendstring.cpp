#include "extendstring.h"
#include <exception>

char * strelyaev::inputString(std::istream & in)
{
  size_t size = 10;
  char * string = new char [size];
  char c = 0;
  size_t i = 0;
  while ((in >> c) && (c != '\n'))
  {
    if (!in)
    {
      delete [] string;
      throw std::logic_error("There is no input");
    }
    string[i++] = c;
    if (i == (size - 1))
    {
      size_t buffer_size = size + 10;
      char * buffer = nullptr;
      try
      {
        buffer = new char [buffer_size];
      }
      catch (...)
      {
        delete [] string;
        string = nullptr;
      }
      if (string == nullptr)
      {
        throw std::logic_error("Unable to create buffer");
      }
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
    throw std::logic_error("Unable to create string");
  }
  return string;
}

int strelyaev::checkRepDgt(const char * const string)
{
  for (size_t i = 0; string[i] != '\0'; i++)
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
