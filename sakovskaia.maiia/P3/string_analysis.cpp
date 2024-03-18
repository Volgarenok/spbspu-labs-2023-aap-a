#include "string_analysis.hpp"
#include <cstddef>

int sakovskaia::checkRep(const char * const string)
{
  for (size_t i = 0; string[i] != '\n'; i++)
  {
    for (size_t j = 0; string[j] != '\n'; j++)
    {
      if ((string[i] == string[j]) && (i != j))
      {
        return 1;
      }
    }
  }
  return 0;
}

void sakovskaia::printRep(const char * const string, char * answer)
{
  size_t a = 0;
  for (size_t i = 0; string[i] != '\n'; i++)
  {
    size_t flag = 0;
    for (size_t j = 0; string[j] != '\n'; j++)
    {
      if (string[i] == answer[j])
      {
        flag += 1;
      }
      if ((string[i] == string[j]) && (i != j) && (flag == 0))
      {
        answer[a++] = string[i];
      }
    }
  }
  answer[a] = '\n';
}
