#include <istream>
#include <iostream>
#include "createlinemissinglatinletters.hpp"
#include "inputline.hpp"

int main()
{
  using namespace piyavkin;
  char * new_line = nullptr;
  const size_t number_letters_alphabet = 26;
  char * alphabet = nullptr;
  std::cin >> std::noskipws;
  try
  {
    new_line = inputLine(std::cin);
    alphabet = new char[number_letters_alphabet] {};
  }
  catch (...)
  {
    std::cerr << "error: line not read\n";
    delete [] new_line;
    return 1;
  }
  std::cin >> std::skipws;
  alphabet = createLineMissingLatinLetters(new_line, alphabet);
  std::cout << alphabet << '\n';
  delete [] new_line;
  delete [] alphabet;
}
