#include "input_string.hpp"

char * lebedev::inputString(std::istream & input)
{
  size_t string_size = 10;
  size_t current_index = 0;
  char * string = new char[string_size];
  char current_char = 0;
  input >> std::noskipws;
  while ((input >> current_char) && (current_char != '\n'))
  {
    if (current_index + 1 == string_size)
    {
      try
      {
        char * buffer = new char[string_size + 5];
        for (size_t i = 0; i < string_size; ++i)
        {
          buffer[i] = string[i];
        }
        delete[] string;
        string = buffer;
        string_size += 5;
      }
      catch (const std::bad_alloc &)
      {
        delete[] string;
        throw;
      }
    }
    string[current_index] = current_char;
    ++current_index;
  }
  string[current_index] = '\0';
  input >> std::skipws;
  return string;
}
