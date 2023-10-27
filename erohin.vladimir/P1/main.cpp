#include <iostream>
#include <stdexcept>

struct SequencePythTriple
{
  SequencePythTriple();
  void operator()(int);
  size_t operator()();
private:
  size_t number_;
  size_t pythtriple_;
};

SequencePythTriple::SequencePythTriple():
  number_(0),
  pythtriple_(0)
{}

int main() {
  int current = 0;
  SequencePythTriple pythtriple;
  do
  {
    std::cin >> current;
    if (!std::cin)
    {
      std::cerr << "Input data is not a number sequence\n";
      return 1;
    }
    else if (current != 0)
    {
      
    }
  }
  while (current != 0);
}
