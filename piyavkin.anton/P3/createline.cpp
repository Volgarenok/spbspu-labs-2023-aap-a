#include "createline.hpp"

char * piyavkin::createLine(char * line, size_t length, size_t & count)
{
  bool alphabet[26] = {};
  char letter = 0;
  size_t size = 0;
  for (size_t i = 0; i < length; ++i)
  {
    if (line[i] >= 'a' && line[i] <= 'z')
    {
      int symbol = line[i] - 'a';
      if (alphabet[symbol] == false)
      {
        --count;
      }
      alphabet[symbol] = true;
    }
  }
  char * new_alphabet = new char[count + 1];
  new_alphabet[count] = '\0';
  for (size_t i = 0; i < 26; ++i)
  {
    if (alphabet[i] == false)
    {
      letter = 'a' + i;
      new_alphabet[size] = letter;
      ++size;
    }
  }
  return new_alphabet;
}
