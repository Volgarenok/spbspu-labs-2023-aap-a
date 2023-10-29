#include <iostream>

int main()
{
  int number = 0;
  std::cin >> number;
  if (!std::cin)
  {
    std::cerr << " Is not a sequence\n";
    return 1;
  }
}
