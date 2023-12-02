#include <iostream>
#include <limits>
#include <cstddef>
#include <stdexcept>

struct Loc_Max_Counter {
  Loc_Max_Counter():
    number_1(0),
    number_2(0),
    number_3(0),
    flag(0),
    count_(0)
  {}

  void count(int num)
  {
    if (number_1 == 0) {
      number_1 = num;
    } else if (number_2 == 0) {
      number_2 = num;
    } else {
      number_3 = num;
      flag = 1;
    }

    if (number_2 >= number_1 && number_2 >= number_3 && number_3 != 0 && flag == 1) {
      size_t max_size = std::numeric_limits< size_t >::max();
      if (count_ == max_size) {
        throw std::logic_error("Sequence is too long\n");
      }
      count_ += 1;
    }
    if (flag == 1) {
      number_1 = number_2;
      number_2 = number_3;
    }
  }

  size_t get_result() const
  {
    if (number_3 == 0) {
      throw std::logic_error("Sequence is too short\n");
    }
    return count_;
  }

private:
  int number_1;
  int number_2;
  int number_3;
  unsigned int flag;
  size_t count_;
};

int main()
{
  Loc_Max_Counter counter;

  int number = 0;
  std::cin >> number;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  }


  if (number != 0) {
    while (number != 0) {
      try
      {
        counter.count(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << e.what();
        return 2;
      }

      std::cin >> number;
      if (!std::cin) {
        std::cerr << "Is not a sequence\n";
        return 1;
      }
    }
  } else {
    std::cerr << "Sequence is too short\n";
    return 2;
  }
  try
  {
    std::cout << counter.get_result() << "\n";
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what();
    return 2;
  }
}
