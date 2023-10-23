#include <iostream>
#include <limits>

int main()
{
  int number = 0;
  size_t count = 0;
  do{
    std::cin >> number;
    if (!std::cin){
      std::cerr << "This is not a sequence\n";
      return 1;
    }
    else if (number != 0){
      size_t max_limit = std::numeric_limits<size_t>::max();
      if (count == max_limit){
        std::cerr << "This sequence has no end\n";
        return 2;
      }
      ++count;
    }
  }
  while (number != 0);
  if (count == 0 || count == 1){
    std::cerr << "This sequence is too short\n";
  }
}
