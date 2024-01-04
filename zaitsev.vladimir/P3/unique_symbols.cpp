#include "unique_symbols.h"
#include <stdexcept>
#include <cstddef>
#include "input.h"

char* zaitsev::uniqueChars(const char* str1, const char* str2)
{
  char* res = nullptr;
  size_t capacity = 0;
  size_t size = 0;
  try
  {
    constexpr size_t basic_size = 20;
    res = new char[basic_size];
    res[0] = '\0';
    capacity = basic_size;
    addUnique(str1, str2, std::addressof(res), std::addressof(capacity), std::addressof(size));
    addUnique(str2, str1, std::addressof(res), std::addressof(capacity), std::addressof(size));
  }
  catch (const std::bad_alloc&)
  {
    delete[] res;
    return nullptr;
  }
  return res;
}

int zaitsev::isCharInStr(const char* str, char c)
{
  if (!str)
  {
    return 0;
  }
  while (*str)
  {
    if (*str == c)
    {
      return 1;
    }
    ++str;
  }
  return 0;
}

void zaitsev::addUnique(const char* basic_str, const char* comp_str, char** res_str, size_t* capacity, size_t* size)
{
  if (!basic_str)
  {
    return;
  }
  const size_t step = 20;
  const char* pos = basic_str;
  while (*pos)
  {
    if (!isCharInStr(comp_str, *pos) && !isCharInStr(*res_str, *pos))
    {
      if (*size == *capacity - 1)
      {
        resizeStr(res_str, *capacity, *capacity + step);
        *capacity += step;
      }
      (*res_str)[*size] = *pos;
      (*res_str)[*size + 1] = '\0';
      ++(*size);
    }
    ++pos;
  }
  return;
}
