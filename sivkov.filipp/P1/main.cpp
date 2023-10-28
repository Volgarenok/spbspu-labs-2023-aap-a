#include <iostream>

int main()
{
  int num = 0;
  std::cin >> num;
  if (!std::cin)
  {
    std::cerr << "is not a seq...\n";
    return 1;
  }
}
