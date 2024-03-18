
#include <iostream>
#include <iomanip>
#include <cctype>

char * removeDigits(char * input);
char * removeLetters(char * input);

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
      throw std::logic_error("where is srting?(");
    }
  }
  std::cin >> std::skipws;
  std::cout << removeDigits(array) << "\n";

}

char * removeDigits(char* input)
{
  char* result = input;
  while (*input)
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

char* removeLetters(char* input) {
  char* result = input;
  while (*input)
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
