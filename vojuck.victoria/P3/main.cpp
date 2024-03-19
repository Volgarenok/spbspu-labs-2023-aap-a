#include <iomanip>
#include "removeDigits.hpp"
#include "removeLetters.hpp"
#include "inputString.hpp"

int main()
{
  std::cin >> std::noskipws;
  int size = 20;
  char * array = nullptr;
  char * result = nullptr;
  try
  {
    array = vojuck::inputString(std::cin, size);
    result = new char[size]{};
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  catch (const std::logic_error &e)
  {
    std::cerr << "Error!\n";
    return 2;
  }
  if (array != nullptr)
  {
    vojuck::removeDigits(array, result);
    std::cout << result << "\n";
    vojuck::removeLetters(array, result);
    std::cout << result << "\n";
  }
  std::cin >> std::skipws;
  delete [] array;
  delete [] result;
}

