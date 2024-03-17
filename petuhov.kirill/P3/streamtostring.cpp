#include "streamtostring.hpp"

char * petuhov::streamToString(std::istream & input)
{
  char sym = 0;
  size_t bufferSize = 1;
  char * string = nullptr;
  char * buffer = nullptr;

  input >> std::noskipws;

  while (input >> sym && sym != '\n')
  {
    if (!input)
    {
      delete[] buffer;
      delete[] string;
      throw std::logic_error("Error reading input");
    }
    try
    {
      buffer = new char[bufferSize + 1];
    }
    catch (const std::bad_alloc &e)
    {
      delete[] string;
      throw;
    }
    if (string != nullptr)
    {
      for (size_t i = 0; i < bufferSize - 1; ++i)
      {
        buffer[i] = string[i];
      }
      delete[] string;
    }
    buffer[bufferSize - 1] = sym;
    buffer[bufferSize] = '\0';
    string = buffer;
  }
  return string;
}
