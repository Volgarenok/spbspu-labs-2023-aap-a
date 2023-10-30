#include <iostream>
#include <limits>

int main() {
  int a = 0, b = 0, c = 1, f = 0;
  size_t counter = 0;
  std::cin >> a;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  else if (a == 0) {
    std::cerr << "Sequence is too short\n";
    return 2;
  }
  std::cin >> b;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  else if (b == 0) {
    std::cerr << "Sequence is too short\n";
    return 2;
  }

  while (c != 0) {
    std::cin >> c;

    if (!std::cin) {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (c == 0 and f == 0) {
      std::cerr << "Sequence is too short\n";
      return 2;
    }
    f = 1;
    if (b >= a and b >= c and c != 0) {
      size_t max_size = std::numeric_limits< size_t >::max();
      if (counter == max_size) {
        std::cerr << "Sequence is too long\n";
        return 2;
      }
      counter += 1;
    }
    a = b;
    b = c;
  }
  std::cout << counter << "\n";
}

