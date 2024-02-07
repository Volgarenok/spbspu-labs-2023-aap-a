#include "input.h"
#include <istream>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <limits>

char* resizeStr(const char* str, size_t old_size, size_t new_size);

char* zaitsev::readStr(std::istream& input)
{
  size_t capacity = 20;
  size_t size = 0;
  char x = '\0';
  char* str = nullptr;

  try
  {
    str = new char[capacity];
    str[0] = '\0';
    input >> std::noskipws >> x;
    while (input)
    {
      if (size + 1 == capacity)
      {
        char* resized_str = resizeStr(str, capacity, capacity * 2);
        delete[] str;
        str = resized_str;
        capacity *= 2;
      }
      if (x == '\n')
      {
        break;
      }
      str[size] = x;
      ++size;
      str[size] = '\0';
      input >> x;
    }
  }
  catch (const std::bad_alloc&)
  {
    input >> std::skipws;
    delete[] str;
    throw;
  }
  input >> std::skipws;

  if (!size && !input)
  {
    delete[] str;
    throw std::ios_base::failure("Wrong Input");
  }

  return str;
}

char* resizeStr(const char* str, size_t old_size, size_t new_size)
{
  char* new_str = new char[new_size];
  std::memcpy(new_str, str, std::min(old_size, new_size));
  return new_str;
}
