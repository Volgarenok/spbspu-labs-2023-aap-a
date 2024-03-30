#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdexcept>
#include "expand_array.hpp"
#include "exclude_common_letters.hpp"
#include "add_numbers.hpp"

int main()
{
  using namespace lopatina;

  char * input = new char[20]{};
  char c = 0;
  size_t i = 0;
  size_t amount = 20;

  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    input[i++] = c;
    if (c == '\n')
    {
      input[i - 1] = 0;
      break;
    }
    if (i == (amount - 1))
    {
      try
      {
        char * new_input = expandArray(input, amount);
        delete [] input;
        input = new_input;
        amount += 1;
      }
      catch (const std::bad_alloc & e)
      {
        std::cerr << e.what();
        delete [] input;
        return 1;
      }
    }
  }
  std::cin >> std::skipws;
  input[i] = '\0';
  if (input[0] == '\0')
  {
    std::cerr << "Empty input\n";
    delete [] input;
    return 1;
  }

  char * result1 = nullptr;
  char * result2 = nullptr;
  try
  {
    const char * string1 = "abc";
    const char * string2 = "g1h2k";
    size_t num_dig = countDigits(string2);

    result1 = new char[amount]{};
    result1 = excludeCommonLetters(input, string1, result1);

    result2 = new char[amount + num_dig]{};
    result2 = addNumbers(input, string2, result2);

    std::cout << "EXC-SND: " << result1 << '\n';
    std::cout << "DGT-SND: " << result2 << '\n';
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what();
    delete [] result1;
    delete [] result2;
    delete [] input;
    return 1;
  }

  delete [] result1;
  delete [] result2;
  delete [] input;
  return 0;
}
