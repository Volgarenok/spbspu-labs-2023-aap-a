#include <iostream>

#include "input.hpp"
#include "output.hpp"
#include "doScale.hpp"

int main()
{
  using namespace vyzhanov;
  Shape* shapes[1000] = {};
  point_t point = { 0.0, 0.0 };
  double ratio = 0.0;
  size_t length = 0;
  try
  {
    inputShapes(shapes, point, ratio, length, std::cin);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "An error has occured: " << e.what();
  }
  catch (const std::exception& e)
  {
    std::cerr << "An error has occured: " << e.what();
    for (size_t i = 0; i < length; i++)
    {
      delete shapes[i];
    }
    return 1;
  }
  if (length == 0)
  {
    std::cerr << "An error has occured: nothing to scale\n";
    for (size_t i = 0; i < length; i++)
    {
      delete shapes[i];
    }
    return 1;
  }
  outputShapes(std::cout, shapes, length);
  std::cout << '\n';
  for (size_t i = 0; i < length; i++)
  {
    doScale(*shapes[i], point, ratio);
  }
  outputShapes(std::cout, shapes, length);
  std::cout << '\n';
  for (size_t i = 0; i < length; i++)
  {
    delete shapes[i];
  }
}
