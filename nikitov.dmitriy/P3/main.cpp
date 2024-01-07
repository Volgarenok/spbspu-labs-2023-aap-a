#include <iostream>
#include <utility>
#include "input_array.hpp"
#include "check_matches.hpp"

int main()
{
  using namespace nikitov;
  std::pair< char*, size_t > firstPair = { nullptr, 0 };
  try
  {
    firstPair = inputArray(std::cin);
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Error: Memory out\n";
    return 1;
  }
  catch (const std::out_of_range& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  const char* firstArray = firstPair.first;
  const size_t firstSize = firstPair.second;

  if (firstArray[0] == '\0')
  {
    std::cerr << "Error: Empty input\n";
    delete[] firstArray;
    return 1;
  }
  const char* secondArray = "abc";
  const size_t secondSize = 3;

  std::cout << checkMatches(firstArray, secondArray, firstSize, secondSize) << '\n';
  delete[] firstArray;

  return 0;
}
