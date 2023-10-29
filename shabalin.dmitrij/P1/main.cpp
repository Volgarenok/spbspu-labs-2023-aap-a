#include <iostream>
#include <limits>

struct SequenceCounter
{
  SequenceCounter():
   count_(0)
  {}

  void count(int)
  {
    size_t max_size = std::numeric_limits<size_t>::max();
    if (count_ == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    ++count_;
  }
  size_t get_result() const
  {
    return count_;
  }
  private:
  size_t count_;
};


int main()
{
  size_t count = 0;
  int CurNum = 0;
  int first; 
  int third;
  int kount = 0;
  SequenceCounter counter;
  do
  {
    std::cin >> CurNum;
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
}
