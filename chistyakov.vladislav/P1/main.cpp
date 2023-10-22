#include<iostream>

int main()
{
  int max_num = 0;
  int counter_now = 0;
  int counter_max = 0;

  while (true)
  {
    int num = 0;
    std::cin >> num;

    if (!std::cin){
      std::cout << "Bad input, try again!";
      return 1;
    }

    if (num > max_num){
      max_num = num;
    }
    else if (num == max_num){
      counter_now += 1;
    }
    else{
      if (counter_now > counter_max){
	counter_max = counter_now;
      }
    }

    if (num == 0){
      std::cout << counter_max;
      break;
    }
  }
  return 0;
}
