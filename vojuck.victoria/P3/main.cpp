
#include <iostream>
#include <iomanip>
#include <cctype>

char * removeDigits(const char * input, char * result);
char * removeLetters(const char * input, char * result);

int main()
{
  int  size = 20;
  char * array = new char[size];
  char * new_array = nullptr;
  char c = 0;
  int i = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> c) && (c != '\n'))
  {
    if (!std::cin)
    {
      delete [] array;
      throw std::logic_error("input error");
    }
    array[i++] = c;
    if (i == (size - 1))
    {
      int  new_size = size + 20;
      try
      {
        new_array = new char[new_size];
        for (size_t j = 0; j < i; j++)
        {
          new_array[j] = array[j];
        }
        delete [] array;
        array = new_array;
        size = new_size;
      }
      catch (const std::bad_alloc &e)
      {
        delete [] array;
        array = nullptr;
      }
    }
    array[i] = '\n';
    if (array[0] == '\n')
    {
      delete [] array;
      throw std::logic_error("where is srting?(\n");
    }
  }
  try
  {
    char * resultDigits = new char[size]{};
    removeDigits(array, resultDigits);
    char * resultLetters = new char[size]{};
    removeLetters(array, resultLetters);
    std::cout << resultDigits << "\n" << resultLetters << "\n";
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  std::cin >> std::skipws;

}

char * removeDigits(const char * input, char * result)
{
  while (*input != '\n')
  {
    if (!std::isdigit(*input))
    {
      *result = *input;
      result++;
    }
    input++;
  }
  *result = '\0';
  return result;
}

char * removeLetters(const char * input, char * result)
{
  while (*input != '\n')
  {
    if (!std::isalpha(*input))
    {
      *result = *input;
      result++;
    }
    input++;
  }
  *result = '\0';
  return result;
}
