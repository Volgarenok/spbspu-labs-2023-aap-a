#include <iostream>
#include <algorithm>

int main()
{
  int curr_element = 1;
  int seq_beg_element = 0;
  int curr_len = 0;
  int max_len = 0;

  while ((std::cin >> curr_element) && curr_element != 0)
  {
    if (curr_element == seq_beg_element)
    {
      ++curr_len;
    }
    else
    {
      max_len = std::max(max_len, curr_len);
      curr_len = 1;
      seq_beg_element = curr_element;
    }
  }

  if (!std::cin)
  {
    std::cerr << "The input data is not a sequence\n";
    return 1;
  }

  std::cout << std::max(curr_len, max_len) << '\n';

  return 0;
}
