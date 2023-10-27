#include <iostream>
#include <stdexcept>
#include <limits>

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

void SequencePythTriple::operator()(int)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (number_ == max_size)
  {
    throw std::logic_error("Sequence is too long");
  }
  ++number_;
}

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
      try
      {
        SequencePythTriple(current);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (current != 0);
}
