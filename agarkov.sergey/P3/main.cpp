#include <iostream>
#include <stdexcept>
#include "inputCStr.hpp"
#include "fillNewRepStr.hpp"
#include "fillNewStrWithoutVow.hpp"

int main()
{
  char* c_str = nullptr;
  try
  {
    c_str = agarkov::inputCStr(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t size = 0;
  while (c_str[size] != '\0')
  {
    size++;
  }
  std::cout << c_str << "\n";

  char* rep_str = nullptr;
  char* vow_str = nullptr;
  try
  {
    rep_str = new char[size/2 + 1];
    vow_str = new char[size];
  }
  catch (const std::bad_alloc& e)
  {
    delete[] c_str;
    delete[] rep_str;
    delete[] vow_str;
    std::cerr << e.what() << "\n";
    return 1;
  }
  agarkov::fillNewRepStr(c_str, rep_str);
  agarkov::fillNewStrWithoutVow(c_str, vow_str);
  std::cout << rep_str << "\n";
  std::cout << vow_str << "\n";
  delete[] c_str;
  delete[] rep_str;
  delete[] vow_str;
}
