#include<iostream>

int main()
{
  int max_num = 0;
  int counter = 0;
  int num = 0;

  std::cin >> num;
  // Input first num and put it in max_num
  if (!std::cin){
      std::cout << "Bad input, try again!";
      return 1;
  }
  if (num == 0){
      std::cout << "There are no numbers in the sequence" << "\n";
      return 2;
  }
  max_num = num;

  while (true)
  {
    int num = 0;
    std::cin >> num;

    if (!std::cin){
      std::cout << "Bad input, try again!";
      return 1;
    }

    if (num == max_num){
      counter += 1;
    }
    else if (num > max_num){
      max_num = num;
      counter = 1;
    }

    if (num == 0){
      std::cout << counter << "\n";
      break;
    }
  }
  return 0;
}
