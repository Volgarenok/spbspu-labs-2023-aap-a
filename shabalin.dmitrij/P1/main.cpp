#include <iostream>

int main()
{
  int CurNum = 0;
  do
  {
    std::cin >> CurNum;
    if (!std::cin)
    {
      std::cerr << ("Is not a sequence\n");
      return 1;
    }
  }
  while (CurNum != 0);
}