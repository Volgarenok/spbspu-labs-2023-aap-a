#include "countNumOfOccurOfLetters.hpp"
#include <cctype>

void chistyakov::countNumOfOccurOfLetters(const char* array, char* dictChar, size_t* dictNumsOfChar)
{
  const size_t numOfCharsInASCII = 128;
  char nowChar = 0;
  size_t i = 0;

  while (array[i] != 0)
  {
    if (isalpha(array[i]))
    {
      nowChar = array[i];

      for (size_t j = 0; j < numOfCharsInASCII; ++j)
      {
        if (dictChar[j] == 0)
        {
          dictChar[j] = nowChar;
          dictNumsOfChar[j] += 1;
          break;
        }
        else if (dictChar[j] == nowChar)
        {
          dictNumsOfChar[j] += 1;
          break;
        }
      }
    }

    i++;
  }
}
