#include <iostream>
#include "locmax.hpp"



int main()
{
  int CurNum = 0;
  int first;
  int kount = 0;
  SequenceCounter counter;
  do
  {
    std::cin >>CurNum;
    if (!std::cin)
    {
      std::cerr << ("Is not a sequence\n");
      return 1;
      }
    else if(CurNum != 0)
    {
     
        
      try 
      {
        counter.count(CurNum);
      }
      catch (const std::exception & e)
      {
        std::cerr << ("Error: ") << e.what() << "\n";
        return 2;
      }
    }
  }
  while (CurNum != 0);
  std::cout << kount;
}
