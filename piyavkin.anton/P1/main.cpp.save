#include <iostream>
#include <stdexcept>
#include "counter.hpp"

int main() {
  long long int num = 1;
  using namespace piyavkin;
  MonDec counter;
  while (num != 0) {
    std::cin >> num;
    if (!std::cin) {
      std::cout << "error\n";
      return 1;
    }
    try {
      counter(num);
    }
    catch (const std::exception& e) {
      std::cerr << "error\n";
      return 2;
    }
  }
  std::cout << counter() << "\n";
}
