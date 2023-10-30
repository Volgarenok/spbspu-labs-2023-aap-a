#include <iostream>
#include <limits>
#include <stdexcept>

struct SequenceCounter {
  SequenceCounter():
    count_(0)
  {}

  void count(int num){
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_ == max_size) {
      throw std::logic_error("Sequence is too long");
    }
    count_ += 1;
  }
  size_t get_result() const
  {
    return count_;
  }
private:
  size_t count_;
};


int main() {
  int number_1 = 0, number_2 = 0, number_3 = 1, flag = 0;
  SequenceCounter counter;

  std::cin >> number_1;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  } else if (number_1 == 0) {
    std::cerr << "Sequence is too short\n";
    return 2;
  }

  std::cin >> number_2;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  } else if (number_2 == 0) {
    std::cerr << "Sequence is too short\n";
    return 2;
  }

  while (number_3 != 0) {
    std::cin >> number_3;

    if (!std::cin) {
      std::cerr << "Is not a sequence\n";
      return 1;
    } else if (number_3 == 0 and flag == 0) {
      std::cerr << "Sequence is too short\n";
      return 2;
    }
    flag = 1;

    if (number_2 >= number_1 and number_2 >= number_3 and number_3 != 0) {
      try {
        counter.count(number_3);
      }
      catch (const std::exception & e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
    number_1 = number_2;
    number_2 = number_3;
  }
  std::cout << counter.get_result() << "\n";
}
