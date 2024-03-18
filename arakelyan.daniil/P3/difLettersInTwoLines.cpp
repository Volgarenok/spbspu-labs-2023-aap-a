#include "difLettersInTwoLines.hpp"
#include <cctype>
#include <cstddef>

void findAndInsertDiffLetters(const char *array, char *answer, size_t &freePos)
{
  for (size_t i = 0; array[i] != '\0'; i++)
  {
    size_t flag = 0;
    if (std::isalpha(array[i]))
    {
      char symb = std::tolower(array[i]);
      for (size_t j = 0; answer[j] != '\0'; j++)
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

void arakelyan::searchForDifferentLettersInTwoLines(const char *inputArr, const char *defaultArray, char *answer)
{
  size_t indexOfUsedCells = 0;
  findAndInsertDiffLetters(inputArr, answer, indexOfUsedCells);
  findAndInsertDiffLetters(defaultArray, answer, indexOfUsedCells);
  for (size_t i = 0; answer[i] != '\0'; i++)
  {
    for (size_t j = 0; answer[j + 1] != '\0'; j++)
    {
      if (std::isalpha(answer[j]) && std::isalpha(answer[j + 1]))
      {
        if (answer[j] > answer[j + 1])
        {
          char temp = answer[j];
          answer[j] = answer[j + 1];
          answer[j + 1] = temp;
        }
      }
    }
  }
  answer[indexOfUsedCells] = '\0';
}
