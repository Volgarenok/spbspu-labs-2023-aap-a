#include <iostream>
#include <limits>

struct Sequens
{
  Sequens():
    count(0),
    lenght(0)
  {}
  bool number_choto(int a, int b)
  {
    if (a % b == 0) {
      return true;
    }
    return false;
  }
  
  void seqLenghtAndCount(int a, int b){
    size_t max_lenght = std::numeric_limits<size_t>::max();
    if (lenght == max_lenght) {
      throw std::logic_error("Sequence is too long.");
    } else if (a == 0 && lenght < 3) {
      throw std::logic_error("Sequence is short.");
    } else {
      if (number_choto(a,b)){
        ++count;
        ++lenght;
      }
    }
  }
  
  size_t get_count() {
    return count;
  }
  
  size_t get_lenght() {
    return lenght;
  }

private:
  size_t count;
  size_t lenght;
};


int main()
{
  int num = 0;
  // int min_len = 0;
  Sequens counter;
  do
  {
    int past = num;
    std::cin >> num;
    // ++min_len;
    if (!std::cin) {
      std::cerr << "Not a num.\n";
      return 1;
    } else if (num == 0 &&  counter.get_lenght() < 2) {
      std::cout << "Sequence is too short.\n";
      return 2;
    } else if (num != 0) {
      try {
        counter.seqLenghtAndCount(num,past); 
      } 
      catch (const std::exception & e) {
        std::cout << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (num != 0);
  std::cout << counter.get_count() <<  "\n";
  return 0;
}
