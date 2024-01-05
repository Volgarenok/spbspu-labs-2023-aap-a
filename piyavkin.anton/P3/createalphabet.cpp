#include "createalphabet.hpp"

size_t piyavkin::createAlphabet(bool * const alphabet, char * line, size_t length)
{
  size_t count = 0;
  for (size_t i = 0; i < length; ++i)
  {
    int symbol = line[i] - 'a';
    if (symbol >= 0 && symbol <= 26)
    {
      if (alphabet[symbol] == false)
      {
        ++count;
      }
      alphabet[symbol] = true;
    }
  }
  return 26-count;
}
