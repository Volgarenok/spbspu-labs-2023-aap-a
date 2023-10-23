#include <iostream>
#include "sequence_counter.cpp"
#include "ismax.cpp"

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
    std::cerr << "Error: This sequence is too short\n";
    return 2;
  }
  std::cout << pre_max << '\n';
  return 0;
}
