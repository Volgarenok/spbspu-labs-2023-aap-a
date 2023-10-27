#include <iostream>
#include <stdexcept>
#include <limits>

struct SequencePythTriple
{
  SequencePythTriple();
  void operator()(int current);
  size_t operator()() const;
private:
  size_t number_;
  size_t pythtriple_;
  size_t prev_;
  size_t pre_prev_;
  bool isPythTriple(int current);
};

SequencePythTriple::SequencePythTriple():
  number_(0),
  pythtriple_(0),
  prev_(0),
  pre_prev_(0)
{}

void SequencePythTriple::operator()(int current)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (number_ == max_size)
  {
    throw std::logic_error("Sequence is too long");
  }
  ++number_;
  if (number_ > 2 && isPythTriple(current))
  {
    ++pythtriple_;
  }
  pre_prev_ = prev_;
  prev_ = current;
}

bool SequencePythTriple::isPythTriple(int current)
{
  size_t a = pre_prev_;
  size_t b = prev_;
  size_t c = current;
  if ((a * a + b * b) == c * c)
  {
    return true;
  }
  else
  {
    return false;
  }
}

size_t SequencePythTriple::operator()() const
{
  return pythtriple_;
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
        pythtriple(current);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (current != 0);
  std::cout << pythtriple() << "\n";
}
