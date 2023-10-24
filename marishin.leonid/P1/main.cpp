#include <iostream>

int main() {
  long long int num;
  std::cin >> num;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  while (num != 0) {
    if (!std::cin) {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
  }
}
