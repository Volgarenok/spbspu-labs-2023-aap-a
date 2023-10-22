#include "mondec.h"
#include <limits>
#include <stdexcept>

/* Специальный метод. Задаёт counter значение 0 */
Mondec::Mondec():
  counter(0)
{}


/* Метод в классе, который проверяет число на переполнение.
так же добавляет к полю counter значение, если все ОК*/
void Mondec::limitCheck(int num)
{
  size_t max_size = std::numeric_limits<size_t>::max();

  if (num = max_size)
  {
    throw std::logic_error("NUMBER IS TOO BIG");
  }
  counter++;
}


/*Метод, возвращающий counter*/
size_t Mondec::resultlog() const
{
  return counter;
}
