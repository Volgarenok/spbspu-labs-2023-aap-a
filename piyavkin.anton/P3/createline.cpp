#include "createline.hpp"

void piyavkin::createLine(bool * alphabet, char * line)
{
  char letter = 0;
  size_t size = 0;
  for (size_t i = 0; i < 26; ++i)
  {
    if (alphabet[i] == false)
    {
      letter = 'a' + i;
      line[size] = letter;
      ++size;
    }
  }
}
