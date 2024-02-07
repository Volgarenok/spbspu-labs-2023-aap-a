#include "unique_symbols.h"
#include "input.h"

int isCharInString(const char* str, char c);

void zaitsev::uniqueChars(const char* str1, const char* str2, char* result_str)
{
  for (char symbol = 1; symbol != 0; ++symbol)
  {
    if (isCharInString(str1, symbol) + isCharInString(str2, symbol) == 1)
    {
      *result_str = symbol;
      ++result_str;
    }
  }
  *result_str = '\0';
  return;
}

int isCharInString(const char* str, char c)
{
  while (str && *str)
  {
    if (*str == c)
    {
      return 1;
    }
    ++str;
  }
  return 0;
}
