#include "inputCStr.hpp"
#include <stdexcept>
#include <istream>

char* agarkov::inputCStr(std::istream& in)
{
  size_t capacity = 10;
  char* c_str = new char[capacity];
  size_t size = 0;

  in >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* new_str = new char[capacity + 20];
        for (auto i = c_str, j = new_str; i != c_str + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] c_str;
        c_str = new_str;
        capacity += 20;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] c_str;
        throw;
      }
    }
    in >> c_str[size];
  }
  while (in && c_str[size++] != '\n');

  if (size <= 1)
  {
    delete[] c_str;
    throw std::invalid_argument("Empty input\n");
  }

  c_str[size - 1] = '\0';
  return c_str;
}
