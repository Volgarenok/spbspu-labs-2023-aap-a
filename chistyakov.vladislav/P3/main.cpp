#include <iostream>
#include <stdexcept>

#include "countNumOfOccurOfLetters.hpp"
#include "sort.hpp"
#include "inputArray.hpp"

int main()
{
  using namespace chistyakov;
  char* array = nullptr;
  const size_t numOfCharsInASCII = 128;

  try
  {
    array = inputArray(std::cin);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }

  char dictChar[numOfCharsInASCII]{};
  size_t dictNumsOfChar[numOfCharsInASCII]{};
  sortByQuantity(array, dictChar, dictNumsOfChar);

  if (dictChar[1] == 0 || dictChar[2] == 0)
  {
    std::cerr << "There are less than 3 letters in the sequence!\n";
    delete[] array;
    return 1;
  }

  char result[] = "abc";
  sortCertainNumberOfItems(dictChar, result, 3);

  std::cout << result << "\n";

  delete[] array;
  return 0;
}
