#include <iostream>

int main()
{
  int num = 0;
  size_t size = 0;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Is not a sequance\n";
      return 1;
    }
    else if (num != 0)
    {
      ++size;
    }
  }
  while (num != 0);
  std::cout << size << "\n";
}
