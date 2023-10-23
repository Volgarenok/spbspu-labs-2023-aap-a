#include <exception>
#include <iostream>
#include <limits>
#include <stdexcept>


// класс последовательности
struct SequensOfNums
{
  SequensOfNums():
    count()
  {}
private:
  size_t count;

public:
  bool lenghtCheck (size_t length,int curr) {
    size_t max_length = std::numeric_limits<size_t>::max();
    if (length == max_length) {
      throw std::logic_error("Sequense is too long\n");
    } else if ((length == 2 && curr == 0) || (curr == 0 && length == 1)) {
      throw std::logic_error("Sequence is too short\n");
    } else {
      return 0;
    }
  }
  void countOfque(int a,int b) {
    if (a % b == 0) {
      ++count;
    }
  }

  size_t get_count() {
    return count;
  }
};


int main()
{
  int currentNum = 0;
  size_t length = 1;
  int pastNum = 0;
  SequensOfNums counttt;

  try {
    std::cin >> currentNum;
    if (!std::cin) {
      std::cerr << "Enter num\n";
      return 1;
    }
    counttt.lenghtCheck(length,currentNum);
    while(currentNum != 0) {
      pastNum = currentNum;
      std::cin >> currentNum;
      if (!std::cin) {
        std::cerr << "Enter num\n";
        return 1;
      }
      ++length;
      counttt.lenghtCheck(length,currentNum);
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
