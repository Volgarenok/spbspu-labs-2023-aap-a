#include "stringManipulations.hpp"
#include <utility>
#include <string>

bool isaychev::checkString(const char * string, const char * strForCheck)
{
  size_t i = 0;
  while (strForCheck[i] != '\0')
  {
    if (strForCheck[i] != string[i])
    {
      return false;
    }
    i++;
  }
  return true;
}

size_t isaychev::countWSpaces(const char * str)
{
  size_t counter = 0, i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == ' ')
    {
      counter++;
    }
    i++;
  }
  return counter;
}

void isaychev::skipParameter(char * str)
{
  size_t i = 0;
  while (str[i] != ' ')
  {
    i++;
  }
  for (size_t j = 0; j < i + 1; j++)
  {
    size_t k = 0;
    while (str[k + 1] != '\0')
    {
      std::swap(str[k], str[k + 1]);
      k++;
    }
    str[k] = '\0';
  }
}

void isaychev::parseParams(char * str, size_t numOfParameters, double * parameters)
{
  size_t pos = 0;
  skipParameter(str);
  char * str2 = str;
  for (size_t j = 0; j < numOfParameters; ++j)
  {
    parameters[j] = std::stod(str2, &pos);
    str2 += pos;
  }
}
