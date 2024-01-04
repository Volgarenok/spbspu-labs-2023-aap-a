#include "sortingByQuantity.hpp"
#include <cstddef>

void chistyakov::sortingByQuantity(char* chars, size_t* nums)
{
  size_t lenght = 0;
  while (nums[lenght] != 0)
  {
    lenght++;
  }

  for (size_t i = 1; i < lenght; ++i)
  {
    size_t timeValueNum = 0;
    char timeValueChar = 0;
    char isSort = 1;
    for (size_t j = 0; j < lenght - i; ++j)
    {
      if (nums[j] < nums[j + 1] && nums[j + 1] != 0)
      {
        timeValueNum = nums[j + 1];
        nums[j + 1] = nums[j];
        nums[j] = timeValueNum;

        timeValueChar = chars[j + 1];
        chars[j + 1] = chars[j];
        chars[j] = timeValueChar;

        isSort = 0;
      }
    }
    if (isSort)
    {
      break;
    }
  }
}
