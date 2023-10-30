#include <iostream>
#include <stdexcept>
#include "sequence_counter.hpp"

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
