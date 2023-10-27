#include <iostream>
#include <stdexcept>

int main() {
  int current = 0;
  do
  {
    std::cin >> current;
    if (!std::cin)
    {
      std::cerr << "Input data is not a number sequence\n";
      return 1;
    }
    else if (current != 0)
    {
      
    }
  }
  while (current != 0);
}
