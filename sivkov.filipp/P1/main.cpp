#include <iostream>
#include <stdexcept>
#include "SequenceCounter.hpp"
int main()
{
  int num = 0;
  int num_old = 0;

  using namespace sivkov;
  SequenceCount counter;

  do
  {
    num_old = num;
    std::cin >> num;

    if (!std::cin)
    {
      std::cerr <<"is not a seq...\n";
      return 1;
    }
    else if (num !=0)
    {
      try
      {
        counter(num, num_old);
      }
      catch (const std::exception & e)
      {
        std::cerr <<"Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while(num != 0);
  std::cout << "Answer: "<<counter() <<"\n";
}
