#include "replace_symbol.hpp"
#include <cstddef>
#include <stdexcept>
#include "lengthen_string.hpp"

char* erohin::replaceSymbol(const char* str, char old, char change)
{
  const size_t iter_size = 20;
  size_t size = iter_size;
  char* result = nullptr;
  try
  {
    result = new char[iter_size + 1]{};
  }
  catch (const std::bad_alloc&)
  {
    return nullptr;
  }
  char* temp = nullptr;
  size_t i = 0;
  while (str[i] != '\0')
  {
    if (i == size)
    {
      try
      {
        temp = lengthenString(result, size, iter_size);
        size += iter_size;
        delete[] result;
        result = temp;
      }
      catch (const std::bad_alloc&)
      {
        delete[] result;
        return nullptr;
      }
    }
    result[i] = (str[i] == old) ? change : str[i];
    ++i;
  }
  result[i] = '\0';
  return result;
}
