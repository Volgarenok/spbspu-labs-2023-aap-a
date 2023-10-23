#include <iostream>
#include <limits>

//класс последовательности
struct SequensOfNums
{
  SequensOfNums():
    count(0),
    lenght(0)
  {}

  //делится или текущ. число на пред
  bool quotientOfNums(int a, int b) {
    if (a % b == 0) {
      return true;
    }
    return false;
  }
  //проверка последовательности. слишком длинная или короткая
  bool lengthCheck(size_t lenght, int curr) {
    size_t max_lenght = std::numeric_limits<size_t>::max();
    if (lenght == max_lenght) {
      throw std::logic_error("Sequence is too long.\n");
    } else if (lenght == 1 && curr == 0) {
      throw std::logic_error("Sequence is too short.\n");
    }
    else {
      return true;
    }
  }
  // подсчет количества пар последовательности
  // которая не нулевая и не слишком большая
  void seqLengthAndCount(int a, int b) {
    // size_t max_lenght = std::numeric_limits<size_t>::max();
    // if (lenght == max_lenght) {
    // throw std::logic_error("Sequence is too long.");
    // }
    // else {
    // if (quotientOfNums(a,b)) {
    // ++count;
    // }
    // }
    if (lengthCheck(lenght, a) && quotientOfNums(a, b)) {
      ++count;
    }
  }

  size_t get_count() {
    return count;
  }

  size_t get_length() {
    return lenght;
  }

private:
  size_t count;
  size_t lenght;
};


int main()
{
  int currentNum = 0;
  SequensOfNums counter;

  do
  {
    int pastNum = currentNum;
    std::cin >> currentNum;   // проверка ввод
    if (!std::cin) {
      std::cerr << "Not a num.\n";
      return 1;
      // } else if (currentNum == 0 && counter.get_length() < 2) {
      // std::cerr << "Seq is too short.\n";
      // return 2;
    }
    else if (currentNum != 0) {
      try {
        counter.seqLengthAndCount(currentNum,pastNum);
      }
      catch (const std::exception & e) {
        std::cout << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (currentNum != 0);
  std::cout << counter.get_count() << " : " <<  counter.get_length() << "\n";
  return 0;
}
