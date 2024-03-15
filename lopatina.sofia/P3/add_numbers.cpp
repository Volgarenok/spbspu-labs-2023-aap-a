#include "add_numbers.hpp"
#include <cctype>

size_t lopatina::countDigits(const char * str)
{
  size_t i = 0, count = 0;
  while (*(str++) != '\0')
  {
    if (std::isdigit(*str))
    {
      count += 1;
    }
    i += 1;
  }
  return count;
}

char * lopatina::addNumbers(const char * first_str, const char * second_str, char * result)
{
  size_t last = 0;
  size_t i = 0, j = 0;
  while (first_str[i] != '\0')
  {
    result[i] = first_str[i];
    i++;
  }
  last = i - 1;
  while (second_str[j] != '\0')
  {
    if (std::isdigit(second_str[j]))
    {
      last += 1;
      result[last] = second_str[j];
    }
    j++;
  }
  result[last + 1] = '\0';
  return result;
}
