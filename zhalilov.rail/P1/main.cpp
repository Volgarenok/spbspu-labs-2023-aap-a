#include <iostream>

class Counter
{
  size_t count;
  size_t maxSeq;
public:
  Counter():
    count(1),
    maxSeq(0)
  {}

  void operator()(int prev, int curr)
  {
    if(curr == prev)
    {
      count++;
    }
    else
    {
      count = 1;
    }

    if(count > maxSeq)
    {
      maxSeq = count;
    }
  }
  
  size_t operator()() const
  {
    return maxSeq;
  }
};

int main()
{
  int prev = 0;
  int curr = 0;
 
  Counter counter;
  while(std::cin >> curr && curr)
  {
    if(!std::cin)
    {
      std::cout << "Bad input";
      return 1;
    }
    counter(prev, curr);
    prev = curr;
  }

  std::cout << counter();
}
