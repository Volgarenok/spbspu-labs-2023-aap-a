#include <iostream>

int main()
{
  int num = 0;
  int k;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "is not a seq...\n";
      return 1;
    }
  }
  while(num != 0);
}
