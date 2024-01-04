#include "input.h"
#include <istream>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <limits>

char* zaitsev::readStr(std::istream& input)
{
  size_t capacity = 20;
  size_t size = 0;
  char x;
  char* str = nullptr;

  try
  {
    str = new char[capacity];
    str[0] = '\0';
    input.get(x);
    while (input)
    {
      if (size + 1 == capacity)
      {
        resizeStr(std::addressof(str), capacity, capacity * 2);
        capacity *= 2;
      }
      if (x == '\n')
      {
        break;
      }
      str[size] = x;
      ++size;
      str[size] = '\0';
      input.get(x);
    }
  }
  catch (const std::bad_alloc& e)
  {
    delete[] str;
    throw;
  }

  if (!size && !input)
  {
    delete[] str;
    return nullptr;
  }

  return str;
}

void zaitsev::resizeStr(char** str, size_t old_size, size_t new_size)
{
  char* new_str = new char[new_size];
  memcpy(new_str, *str, std::min(old_size, new_size));
  char* temp = *str;
  *str = new_str;
  delete[] temp;
}
