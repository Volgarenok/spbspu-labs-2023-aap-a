#include <iostream>
#include <limits>
#include <stdexcept>

struct MonDec{
  MonDec():
    count_(0),
    maxc(0),
    prev(std::numeric_limits< long long int >::max())
  {}
  void operator()(long long int num) {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_ == max_size) {
      throw std::logic_error("error\n");
    }
    else if (num == 0) {
      if (count_ > maxc) {
        maxc = count_;
      }
    }
    else if (num <= prev) {
      ++count_;
    }
    else {
      if (count_ > maxc) {
        maxc = count_;
      }
      count_ = 1;
    }
    prev = num;
  }
  size_t operator()() const {
    return maxc;
  }
private:
  size_t count_;
  size_t maxc;
  long long int prev;
};

int main() {
  long long int num = 1;
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
