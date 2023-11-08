#include "local_max_counter.hpp"


kovtun::LocalMaxCounter::LocalMaxCounter():
  counter_()
{}

void kovtun::LocalMaxCounter::operator()(int number)
{

}

size_t kovtun::LocalMaxCounter::operator()()
{
  return counter_;
}