#include "mondec.h"
#include <limits>
#include <stdexcept>
#include <iostream>
/* Специальный метод. Задаёт counter значение 0 */
Mondec::Mondec():
  max_counter(0),
  new_counter(1),
  past_number(0)
{}


/* Метод в классе, который проверяет число на переполнение.
так же добавляет к полю counter значение, если все ОК*/
void Mondec::numberCheck(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (new_counter == max_size)
  {
    throw std::logic_error("SEQUENCE IS TOO BIG");
  }
  if (past_number >= num)
  {
    ++new_counter;
  }
  else
  {
    new_counter = 1;
  }
    past_number = num;
}


/*Метод, который сравнивает max_counter с new_counter*/
void Mondec::counterCheck()
{
  if (new_counter > max_counter)
  {
    max_counter = new_counter;
  }
}


/*Метод, возвращающий counter*/
size_t Mondec::resultlog() const
{
  return max_counter;
}
