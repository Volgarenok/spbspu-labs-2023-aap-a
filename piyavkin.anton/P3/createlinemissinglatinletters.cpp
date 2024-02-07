#include "createlinemissinglatinletters.hpp"
#include <cstddef>

bool piyavkin::checkExistenceLetter(const char letter, const char * line)
{
  size_t i = 0;
  while (line[i] != '\0')
  {
    if (line[i++] == letter)
    {
      return true;
    }
  }
  return false;
}

char * piyavkin::createLineMissingLatinLetters(const char * line, char * alphabet)
{
  size_t count = 0;
  for (char i = 'a'; i <= 'z'; ++i)
  {
    if (!checkExistenceLetter(i, line))
    {
      alphabet[count++] = i;
    }
  }
  return alphabet;
}
