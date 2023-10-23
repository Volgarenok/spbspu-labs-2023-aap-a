#include <iostream>
#include <limits>

void isMax(int now, int& actual, int& pre)
{
  if (now >= actual){
    pre = actual;
    actual = now;
  }
}

struct SequenceCounter
{
  SequenceCounter():
    count_(0)
   {}

  void isLimit(int)
  {
    size_t max_limit = std::numeric_limits<size_t>::max();
    if (count_ == max_limit){
      throw std::logic_error("This sequence has no end\n");
    }
    ++count_;
  }
  size_t check_count()
  {
    return count_;
  }
  private:
    size_t count_;
};

int main()
{
  int number = 0;
  int actual_max = 0;
  int &act = actual_max;
  int pre_max = 0;
  int &pre = pre_max;
  SequenceCounter counter;
  do{
    std::cin >> number;
    if (!std::cin){
      std::cerr << "Error: This is not a sequence\n";
      return 1;
    }
    else if (number != 0){
      try{
        counter.isLimit(number);
      } catch (const std::exception & e){
      std::cerr << "Error: " << e.what() << '\n';
      return 2;
      }
      isMax(number, act, pre);
    }
  }
  while (number != 0);
  if (counter.check_count() == 0 || counter.check_count() == 1){
    std::cerr << "Error This sequence is too short\n";
    return 2;
  }
  std::cout << pre_max << '\n';
  return 0;
}
