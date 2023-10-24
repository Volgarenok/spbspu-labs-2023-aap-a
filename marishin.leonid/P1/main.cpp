#include <iostream>
#include <limits>
#include <stdexcept>

namespace marishin {
  class Sequence {
  
  }
}

int main() {
  long long int num;
  std::cin >> num;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  while (true) {
    if (!std::cin) {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    std::cin >> num;
  }
}
