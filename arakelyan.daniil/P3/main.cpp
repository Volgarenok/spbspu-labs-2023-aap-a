#include <exception>
#include <iostream>
#include <new>
#include <stdexcept>
#include "inputLine.hpp"
#include "difLetters.hpp"
#include "difLettersInTwoLines.hpp"

int main()
{
  char *inputString = nullptr;
  const char *defaultStringForTaskTwo = "def ghk";

  try
  {
    inputString = arakelyan::inputArray(std::cin);
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }


  using namespace arakelyan;
  size_t answerTaskOne = countOfDifferentLetters(inputString);

  size_t sizeOfAlphabet = 'z' - 'a' + 1;
  char * answerTaskTwo = nullptr;

  try
  {
    answerTaskTwo = new char[sizeOfAlphabet + 1]{};
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Cannot create a dynamic array for aswer of second task!\n";
    delete [] inputString;
    return 1;
  }

  searchForDifferentLettersInTwoLines(inputString, defaultStringForTaskTwo, answerTaskTwo);

  std::cout << answerTaskOne << "\n" << answerTaskTwo << "\n";

  delete [] answerTaskTwo;
  delete [] inputString;
  return 0;
}
