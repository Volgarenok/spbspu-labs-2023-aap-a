#include <iostream>
#include "sequenceofnums.hpp"

int main()
{
  int currentNum = 0;
  size_t length = 1;
  int pastNum = 0;
  using namespace arakelyan;
  SequenceOfNums counttt;

  try {
    std::cin >> currentNum;
    if (!std::cin) {
      std::cerr << "Enter num\n";
      return 1;
    }
    counttt.lengthCheck(length,currentNum);
    while(currentNum != 0) {
      pastNum = currentNum;
      std::cin >> currentNum;
      if (!std::cin) {
        std::cerr << "Enter num\n";
        return 1;
      }
      ++length;
      counttt.lengthCheck(length,currentNum);
      if (currentNum != 0) {
        counttt.countOfque(currentNum,pastNum);
      }
    }
  } catch(const std::exception & e) {
    std::cout << "Error: " << e.what() << "\n";
    return 2;
  }
  std::cout << "Ansver: " << counttt.get_count() << "\n";
  return 0;
}
