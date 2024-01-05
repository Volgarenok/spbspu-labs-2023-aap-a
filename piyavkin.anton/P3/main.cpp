#include "cpline.hpp"
#include "createalphabet.hpp"
#include "createline.hpp"
#include <iostream>

int main()
{
  using namespace piyavkin;
  size_t length = 0;
  char sym = 0;
  char * new_line = nullptr;
  char * old_line = nullptr;
  std::cin >> std::noskipws;
  while (std::cin >> sym)
  {
    old_line = new_line;
    try
    {
      new_line = new char [length + 1]{};
    }
    catch (std::bad_alloc&)
    {
      std::cerr << "Dynamic memory overflow\n";
      delete [] old_line;
      return 1;
    }
    cpLine(old_line, new_line, length);
    new_line[length] = tolower(sym);
    ++length;
    if (sym == '\n')
    {
      break;
    }
  }
  std::cin >> std::skipws;
  if (new_line != nullptr)
  {
    new_line[length-1] = '\0';
  }
  else
  {
    std::cerr << "Line not read\n";
    return 1;
  }
  bool alphabet [26] = {};
  size_t count = createAlphabet(alphabet, new_line, length);
  delete [] new_line;
  char * new_alphabet = nullptr;
  try
  {
    new_alphabet = new char [count+1];
  }
  catch (...)
  {
    std::cerr << "Dynamic memory overflow\n";
    return 1;
  }
  new_alphabet[count] = '\0';
  createLine(alphabet, new_alphabet);
  for (size_t i = 0; i < count+1; ++i)
  {
    std::cout << new_alphabet[i];
  }
  std::cout << '\n';
  delete [] new_alphabet;
}
