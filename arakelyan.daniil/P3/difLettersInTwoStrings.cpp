#include "difLettersInTwoStrings.hpp"
#include <cctype>

void arakelyan::findAndPasteDiffSymb(const char *array, char *answer, size_t &freePos)
{
  size_t flag = 0;
  for (size_t i = 0; array[i] != '\0'; i++)
  {
    if (std::isalpha(array[i]))
    {
      char symb = std::tolower(array[i]);
      for (size_t j = 0; j < 26; j++)
      {
        if (answer[j] == symb)
        {
          flag++;
        }
      }
      if (flag == 0)
      {
        answer[freePos++] = symb;
      }
      flag = 0;
    }
  }
}

void arakelyan::differentLetters(const char *inputArr, const char *defaultArray, char *answer)
{
  for (size_t i = 0; i < 27; i++)
  {
    answer[i] = 1;
  }
  size_t indexOfUsedCells = 0;
  arakelyan::findAndPasteDiffSymb(inputArr, answer, indexOfUsedCells);
  arakelyan::findAndPasteDiffSymb(defaultArray, answer, indexOfUsedCells);
  for (size_t i = 0; i < 27; i++)
  {
    for (size_t j = 0; j < 27 - i; j++)
    {
      if (std::isalpha(answer[j]) && std::isalpha(answer[j+1]))
      {
        if (answer[j] > answer[j+1])
        {
          size_t temp = answer[j];
          answer[j] = answer[j + 1];
          answer[j + 1] = temp;
        }
      }
    }
  }
  answer[indexOfUsedCells + 1] = '\0';
}
