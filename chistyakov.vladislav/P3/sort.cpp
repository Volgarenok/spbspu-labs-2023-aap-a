#include "sort.hpp"
#include <cstddef>

char* chistyakov::sort(char* array, char* result, size_t lenght)
{
  for (size_t i = 1; i < lenght; ++i)
  {
    char timeValue = 0;
    char isSort = 1;
    for (size_t j = 0; j < lenght - i; ++j)
    {
      if (array[j] > array[j + 1])
      {
        timeValue = array[j + 1];
        array[j + 1] = array[j];
        array[j] = timeValue;
        isSort = 0;
      }
    }
    if (isSort)
    {
      break;
    }
  }

  for (size_t i = 0; i < lenght; ++i)
  {
    result[i] = array[i];
  }

  return result;
}
