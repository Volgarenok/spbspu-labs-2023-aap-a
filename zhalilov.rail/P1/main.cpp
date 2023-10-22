#include <iostream>

int main()
{
  int prev = 0;
  int curr = 0;

  size_t counter = 1;
  size_t maxSeq = 0;
  while(std::cin >> curr && curr)
  {
    if(curr == prev)
    {
      counter++;
    }
    else
    {
      counter = 1;
    }

    if(counter > maxSeq)
    {
      maxSeq = counter;
      counter = 1;
    }
    prev = curr;
  }

  std::cout << maxSeq;
}
