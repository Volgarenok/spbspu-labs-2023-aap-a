#include "ioString.hpp"
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <cstring>

namespace prisyach
{

char* inputTheString(std::istream& inp, size_t& size)
{
  size_t capacity = 11;
  char* cStr = nullptr;
  try
  {
    cStr = new char[capacity];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Can't allocate memory" << '\n';
    throw;
  }
  char chInp = '\0';
  inp >> std::noskipws;
  for (inp >> chInp; (inp && chInp) && (chInp != '\n'); inp >> chInp)
  {
    if (size + 1 == capacity)
    {
      capacity = capacity + 10;
      char* dupStr = nullptr;
      try
      {
        dupStr = new char[capacity];
      }
      catch (const std::bad_alloc &e)
      {
        delete[] cStr;
        std::cerr << "Can't allocate memory" << '\n';
        throw;
      }
      cStr[size] = '\0';
      dupStr = std::strcpy(dupStr, cStr);
      delete[] cStr;
      cStr = dupStr;
    }
    cStr[size++] = chInp;
  }
  if (size == 0)
  {
    delete[] cStr;
    throw std::logic_error("Empty string");
  }
  cStr[size] = '\0';
  return cStr;
}

void outputTheString(char* string, size_t size)
{
  for(size_t i = 0; i < size; ++i)
  {
    std::cout << string[i];
  }
}

}


