#include "countChars.hpp"
#include <cctype>
#include "sortingByQuantity.hpp"

void chistyakov::countChars(char* array, char* dictChar, size_t* dictNumsOfChar)
{
  char nowChar = 0;
  size_t i = 0;

  while (array[i] != 0)
  {
    if (isalpha(array[i]))
    {
      nowChar = array[i];

      for (int j = 0; j < 52; ++j)
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
