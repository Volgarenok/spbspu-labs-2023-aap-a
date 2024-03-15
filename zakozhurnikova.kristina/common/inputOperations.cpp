#include "inputOperations.hpp"

char* extendBuffer(const char* string, size_t newSize)
{
  if (!string)
  {
    return new char[newSize]{};
  }
  char* result = new char[newSize] {};
  size_t i = 0;
  for (; string[i] != '\0'; ++i)
  {
    result[i] = string[i];
  }
  result[i] = '\0';
  return result;
}

char* zakozhurnikova::readString(std::istream& input, size_t& stringSize)
{
  size_t bufferSize = 20;
  char c = '\0';
  size_t counter = 0;
  input >> std::noskipws;
  char* string = nullptr;
  try
  {
    string = new char[stringSize]{};
    while (input >> c)
    {
      if (counter == stringSize - 1)
      {
        char* extendedString = extendBuffer(string, stringSize + bufferSize);
        delete[] string;
        string = extendedString;
        stringSize += bufferSize;
      }
      string[counter] = c;
      ++counter;
      if (c == '\n')
      {
        if (counter == 1)
        {
          delete[] string;
          input >> std::skipws;
          throw std::logic_error("Empty string");
        }
        string[counter - 1] = '\0';
        break;
      }
    }
    if (string[0] == '\0')
    {
      delete[] string;
      input >> std::skipws;
      throw std::range_error("Failed string reading");
    }
  }
  catch (const std::bad_alloc& e)
  {
    delete[] string;
    input >> std::skipws;
    throw std::runtime_error("Error while handling a string");
  }
  input >> std::skipws;
  return string;
}
