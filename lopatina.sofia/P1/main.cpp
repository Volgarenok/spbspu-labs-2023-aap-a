#include <iostream>

int main()
{
  int number = 0, number_1 = 0, number_2 = 0, number_3 = 0, counter = 0, flag = 0;

  std::cin >> number;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  }

  if (number != 0) {
    while (number != 0) {

      if (number_1 == 0) {
        number_1 = number;
      } else if (number_2 == 0) {
        number_2 = number;
      } else {
        number_3 = number;
        flag = 1;
      }

      if (number_2 >= number_1 && number_2 >= number_3 && number_3 != 0 && flag == 1) {
        counter += 1;
      }
      if (flag == 1) {
        number_1 = number_2;
        number_2 = number_3;
      }

      std::cin >> number;
      if (!std::cin) {
        std::cerr << "Is not a sequence\n";
        return 1;
      }
    }
    if (number_3 == 0) {
      std::cerr << "Sequence is too short\n";
      return 2;
    } else {
      std::cout << counter;
    }
  } else {
    std::cerr << "Sequence is too short\n";
    return 2;
  }
}
