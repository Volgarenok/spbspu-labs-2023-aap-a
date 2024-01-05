#include <iostream>
#include "inputString.hpp"
#include "deleteDigits.hpp"

int main()
{
  char * string = nullptr;
  size_t size = 20;
  char * result = nullptr;

  try
  {
    string = baranov::inputString(std::cin, size);
    result = new char[size]{0};
  }
  catch (const std::logic_error & e)
  {
    delete[] string;
    delete[] result;
    std::cerr << "Error: " << e.what() << '\n';
    return 2;
  }
  catch (const std::bad_alloc & e)
  {
    delete[] string;
    delete[] result;
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  baranov::deleteDigits(string, result);
  std::cout << result << '\n';

  delete[] string;
  delete[] result;
}

