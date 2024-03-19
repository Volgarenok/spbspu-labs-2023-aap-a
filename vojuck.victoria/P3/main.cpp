#include <iomanip>
#include "removeDigits.hpp"
#include "removeLetters.hpp"
#include "inputString.hpp"

int main()
{
  std::cin >> std::noskipws;
  int size = 20;
  char * array = nullptr;
  try
  {
    array = vojuck::inputString(std::cin, size);
    char * result = new char[size]{};
    vojuck::removeDigits(array, result);
    std::cout << result << "\n";
    vojuck::removeLetters(array, result);
    std::cout << result << "\n";
    delete [] result;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
  std::cin >> std::skipws;
  delete [] array;
}

