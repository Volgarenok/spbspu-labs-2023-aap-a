#include <iostream>
#include <stdexcept>
#include "inputArray.hpp"
#include "difLetters.hpp"
#include "difLettersInTwoStrings.hpp"

int main()
{
  char *inputString = nullptr;
  const char *defaultStringForTaskTwo = "def ghk";

  try
  {
    inputString = arakelyan::inputArray(std::cin);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Memory cannot be allocated in input process!\n";
    return 1;
  }

  using namespace arakelyan;
  size_t answerTaskOne = countOfdifferentLetters(inputString);

  char *answerTaskTwo = nullptr;
  try
  {
    answerTaskTwo = new char[26 + 1];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Cannot create a dynamic array for answer of second task!\n";
    delete [] inputString;
    return 1;
  }

  differentLetters(inputString, defaultStringForTaskTwo, answerTaskTwo);

  std::cout << answerTaskOne << "\n" << answerTaskTwo << "\n";

  delete [] answerTaskTwo;
  delete [] inputString;
  return 0;
}
