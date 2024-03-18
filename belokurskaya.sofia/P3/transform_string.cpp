#include "transform_string.hpp"

void belokurskaya::transformString(const char* input, char* not_input_chars)
{
  const int the_size_of_the_latin_alphabet = 26;
  int is_letter_present[the_size_of_the_latin_alphabet] = {0};

  for (size_t i = 0; input[i] != '\0'; ++i)
  {
    char c = std::tolower(input[i]);
    if (std::isalpha(c))
    {
      if (c - 'a' >= 0 && c - 'a' < the_size_of_the_latin_alphabet)
      {
        is_letter_present[c - 'a'] = 1;
      }
    }
  }

  size_t j = 0;
  for (int i = 0; i < the_size_of_the_latin_alphabet; ++i)
  {
    if (!is_letter_present[i])
    {
      if (j < the_size_of_the_latin_alphabet)
      {
        not_input_chars[j++] = static_cast< char >('a' + i);
      }
    }
  }

  if (j < the_size_of_the_latin_alphabet)
  {
    not_input_chars[j] = '\0';
  }
}

void belokurskaya::toLowerCase(char* input)
{
  for (size_t i = 0; input[i] != '\0'; ++i)
  {
    if (std::isalpha(input[i]) && std::isupper(input[i]))
    {
      input[i] = std::tolower(input[i]);
    }
  }
}

