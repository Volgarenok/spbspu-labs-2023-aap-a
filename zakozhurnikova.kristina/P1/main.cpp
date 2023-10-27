#include <iostream>
int main ()
{
  int number = 0;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not sequence\n";
      return 1;
    }
  }
  while (number != 0);
}
