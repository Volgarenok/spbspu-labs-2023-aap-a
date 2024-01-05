#include "transform_string.hpp"
#include "reading_a_string.hpp"

int main()
{
  try
  {
    char * input_str = inputString(std::cin);
    char * not_input_chars = new char[26]{};

    transformString(input_str, nullptr, not_input_chars);

    std::cout << not_input_chars << '\n';

    char* original_input_str = resizeStringBuffer(input_str, std::strlen(input_str), std::strlen(input_str) + 1);

    toLowerCase(original_input_str);

    std::cout << original_input_str << '\n';

    delete[] not_input_chars;
    delete[] original_input_str;
    delete[] input_str;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
