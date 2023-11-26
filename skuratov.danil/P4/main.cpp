#include <iostream>
#include <stdexcept>
#include "task.h"

int main(int argc, char* argv[])
{
  try
  {
    skuratov::performTask(skuratov::readParameters(argc, argv));
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}
