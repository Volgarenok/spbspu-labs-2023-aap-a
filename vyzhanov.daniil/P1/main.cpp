#include <iostream>

int main()
{
  int num = 0;
  do
  {
    std::cin >> num;
    if(!std::cin)
    {
      std::cerr << "Is not a sequance\n";
      return 1;
    }
  }
  while(num != 0);
}
