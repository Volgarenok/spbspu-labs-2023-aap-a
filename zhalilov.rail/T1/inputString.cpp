#include "inputString.hpp"

char *zhalilov::resizeString(char string[], const size_t oldSize, const size_t newSize)
{
  char *temp = new char[newSize];
  size_t dataIndex = 0;
  while (dataIndex < oldSize && dataIndex < newSize)
  {
    temp[dataIndex] = string[dataIndex];
    dataIndex++;
  }
  for (size_t i = oldSize; i < newSize - 1; i++)
  {
    temp[i] = 0;
  }
  temp[newSize - 1] = '\0';
  return temp;
}

char *zhalilov::inputString(std::istream &input)
{
  size_t strSize = 100;
  size_t dataIndex = 0;
  char *string = nullptr;
  string = new char[strSize]{};
  input >> std::noskipws;
  char temp = 0;
  while (input >> temp)
  {
    if (temp == '\n')
    {
      string[dataIndex] = '\0';
      break;
    }
    else
    {
      string[dataIndex] = temp;
    }
    if (dataIndex + 2 == strSize)
    {
      try
      {
        char *newStr = resizeString(string, strSize, strSize + 40);
        delete[] string;
        string = newStr;
        strSize += 40;
      }
      catch (const std::bad_alloc &e)
      {
        delete[] string;
        input >> std::skipws;
        throw;
      }
    }
    dataIndex++;
  }
  if (!input)
  {
    delete[] string;
    input >> std::skipws;
    throw std::invalid_argument("interrupted input");
  }
  input >> std::skipws;
  return string;
}
