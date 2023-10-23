#include <limits>
#include <stdexcept>
#include <iostream>
#include "moninc.hpp"

namespace spiridonov
{
  spiridonov::Moninc::Moninc():
    max_length(0),
    curr_length(0),
    prev_num(0)
  {}

  void spiridonov::Moninc::Moninc::operator()(int num) // Метод, проверяющий на переполнение
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (curr_length == max_size)
    {
      throw std::logic_error("The sequence is too big");
    }
    if (prev_num < num)
    {
      ++curr_length;
    }
    else
    {
      curr_length = 1;
    }
      prev_num = num;
  }

  void spiridonov::Moninc::Moninc::operator()() // Метод сравнения
  {
    if (curr_length > max_length)
    {
      max_length = curr_length;
    }
  }
  size_t spiridonov::Moninc::Moninc::output() const // Метод, возвращающий максимальную длину
  {
    return max_length;
  }
}
