#include <iostream>
#include <limits>

int main() {
  long long int num = 1;
  long long int max_ll = std::numericlimits< long long int >::max();
  long long int prev = max_ll;
  size_t count = 0;
  size_t maxc = 0;
  while (num != 0) {
    std::cin >> num;
    if (!std::cin) {
      std::cout << "error\n";
      return 1;
    }
    else if (num == 0) {
      std::cout << maxc;
    }
    else if (num <= prev) {
      if (count == max_ll) {
        std::cout << "error\n";
        return 2;
      }
      ++count;
    }
    else {
      if (count > maxc) {
        maxc = count;
      }
      count = 1;
    }
    prev = num;
  }
}
