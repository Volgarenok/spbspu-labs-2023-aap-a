#include "sign_change_counter.hpp"


kovtun::SignChangeCounter::SignChangeCounter():
  counter_(0),
  previousNumber_(0)
{}

void kovtun::SignChangeCounter::operator()(int number)
{

}

size_t kovtun::SignChangeCounter::operator()()
{
  return counter_;
}