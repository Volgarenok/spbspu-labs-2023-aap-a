#include <iostream>
#include "Subseq_len_counter.h"

int main()
{
  long long curr_element = 1;
  zaitsev::Subseq_len_counter counter;

  while ((std::cin >> curr_element) && curr_element != 0)
  {
    try
    {
      counter(curr_element);
    }
    catch (const std::exception &e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
  }

  if (!std::cin)
  {
    std::cerr << "The input data is not a sequence\n";
    return 1;
  }

  std::cout << counter.get_max_len() << '\n';

  return 0;
}
