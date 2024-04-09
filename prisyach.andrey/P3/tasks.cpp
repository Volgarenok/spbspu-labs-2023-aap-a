#include "tasks.hpp"
#include <cstddef>
#include <cstring>

namespace prisyach
{

int isDuplicateCharacters(const char* str, size_t sizeStr)
{
  for (size_t i = 0; i < sizeStr - 1; ++i)
  {
    for (size_t j = i + 1; j < sizeStr; ++j)
    {
      if (str[i] == str[j])
      {
        return 1;
      }
    }
  }
  return 0;
}

char* mergeStrings(const char* str1, const char* str2, size_t sizeStr1)
{
  const size_t sizeStr2 = 3;
  char* result = new char[sizeStr1 + sizeStr2 + 1];
  size_t i, j, k;
  i = j = k = 0;
  while (i < sizeStr1 || j < sizeStr2)
  {
    if (i < sizeStr1 && std::strchr(str2, str1[i]) == nullptr)
    {
      result[k++] = str1[i++];
    }
    else if (j < sizeStr2 && std::strchr(str1, str2[j]) == nullptr)
    {
      result[k++] = str2[j++];
    }
    else
    {
      i++;
      j++;
    }
  }
  result[k] = '\0';
  return result;
}

}
