#include "unite_string.hpp"
#include <cstddef>
#include <stdexcept>
#include "lengthen_string.hpp"

char* erohin::uniteString(const char* str1, const char* str2)
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
  size_t j = 0;
  while (str1[i] != '\0' || str2[j] != '\0')
  {
    if (i + j == size)
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
    if (str1[i] != '\0')
    {
      result[i + j] = str1[i];
      ++i;
    }
    if (str2[j] != '\0')
    {
      result[i + j] = str2[j];
      ++j;
    }
  }
  result[i + j] = '\0';
  return result;
}
