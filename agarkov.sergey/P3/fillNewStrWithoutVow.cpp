#include "fillNewStrWithoutVow.hpp"

bool isVowels(char ch)
{
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

void agarkov::fillNewStrWithoutVow(const char* source, char* dest)
{
  for (auto i = source; *i != '\0'; i++)
  {
    if (!isVowels(*i))
    {
      *dest = *i;
      dest++;
    }
  }
  *dest = '\0';
}
