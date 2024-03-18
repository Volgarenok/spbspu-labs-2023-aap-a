#include "reading_a_string.hpp"

#include <iostream>
#include <cstring>

char* belokurskaya::resizeStringBuffer(const char* my_string, const size_t size, const size_t new_memory)
{
  char* result = new char[new_memory + 1]{};

  std::copy(my_string, my_string + size, result);
  result[size] = '\0';

  return result;
}

char* belokurskaya::inputString(std::istream& input)
{
  const int initial_size_of_memory = 20;
  const int new_memory = 10;

  char* input_str = new char[initial_size_of_memory + 1]{};
  char c = '\0';
  int index = 0;
  int size_of_memory = initial_size_of_memory;

  input >> std::noskipws;
  try
  {
    while ((input >> c) && c != '\n')
    {
      input_str[index++] = c;
      if (index > size_of_memory)
      {
        char* temp = new char[size_of_memory + new_memory + 1]{};
        std::copy(input_str, input_str + size_of_memory, temp);
        delete[] input_str;
        input_str = temp;
        size_of_memory += new_memory;
      }
    }
    input >> std::skipws;

    input_str[index] = '\0';

    if (input_str[0] == 0)
    {
      throw std::logic_error("Invalid input");
    }
    return input_str;
  }
  catch (...)
  {
    delete[] input_str;
    throw;
  }
}
