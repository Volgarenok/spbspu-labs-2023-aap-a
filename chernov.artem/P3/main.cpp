#include "deleteDecimalDigits.hpp"
#include "deleteVowels.hpp"

#include <iostream>
#include <cstddef>
#include <cctype>
#include <new>

int main()
{
  using namespace chernov;
  size_t sizeOfInput = 20;

  char* input = nullptr;
  char* oldInput = nullptr;
  try
  {
    input = new char[sizeOfInput]();
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << "\n";
    return 1;
  }

  char c = 0;
  size_t i = 0;

  std::cin >> std::noskipws;

  bool hasNonSpace = false;
  while (std::cin >> c)
  {
    if (!std::cin)
    {
      std::cerr << "Error input\n";
      delete[] input;
      return 1;
    }
    if (i < sizeOfInput - 1)
    {
      input[i++] = c;
      if (!std::isspace(c))
      {
        hasNonSpace = true;
      }
      if (c == '\n')
      {
        input[i - 1] = '\0';
        break;
      }
    }
    else
    {
      sizeOfInput *= 2;

      try
      {
        oldInput = new char[sizeOfInput]();
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Allocation failed: " << e.what() << "\n";
        delete[] input;
        return 1;
      }

      for (size_t k = 0; k < i; ++k)
      {
        oldInput[k] = input[k];
      }

      delete[] input;
      try
      {
        input = new char[sizeOfInput]();
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Allocation failed: " << e.what() << "\n";
        delete[] oldInput;
        return 1;
      }

      for (size_t k = 0; k < i; k++)
      {
        input[k] = oldInput[k];
      }

      input[i++] = c;
      if (c == '\n')
      {
        input[i - 1] = '\0';
        break;
      }
      delete[] oldInput;
    }
  }

  if (!hasNonSpace)
  {
    std::cerr << "Empty input\n";
    delete[] input;
    return 1;
  }

  char* stringWithDecimalDigitsRemoved = nullptr;
  char* stringWithVowelsRemoved = nullptr;

  try
  {
    stringWithDecimalDigitsRemoved = new char[sizeOfInput]();
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << "\n";
    delete[] input;
    return 1;
  }

  try
  {
    stringWithVowelsRemoved = new char[sizeOfInput]();
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << "\n";
    delete[] stringWithDecimalDigitsRemoved;
    delete[] input;
    return 1;
  }

  char* withoutDecimalDigits = removeDecimalDigits(input, stringWithDecimalDigitsRemoved, sizeOfInput);
  char* withoutVowels = removeVowels(input, stringWithVowelsRemoved, sizeOfInput);

  std::cout << withoutDecimalDigits << "\n";
  std::cout << withoutVowels << "\n";

  delete[] stringWithDecimalDigitsRemoved;
  delete[] stringWithVowelsRemoved;
  delete[] input;
  return 0;
}
