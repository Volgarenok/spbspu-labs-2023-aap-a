#include <iostream>
#include <limits>
#include <stdexcept>

int main() {
  size_t count = 0;
  int num = 0;
  std::cin >> num;
  if (!std::cin) {
	  std::cerr << "It is not a number\n";
	  return 1;
  }
  while (num != 0) {
	  std::cin >> num;
	  if (!std::cin) {
		  std::cerr << "It is not a number\n";
		  return 1;
	  }
	  ++count;
  }
  std::cout << count << "\n";	
  return 0;
}
