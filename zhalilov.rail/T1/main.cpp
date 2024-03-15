#include <iostream>

#include "inputShapesSource.hpp"
#include "outputShapesSource.hpp"
#include "isoScale.hpp"

int main()
{
  using namespace zhalilov;
  Shape *shapes[1000] = {};
  point_t point = { 0.0, 0.0 };
  double ratio = 0.0;
  size_t length = 0;
  try
  {
    inputShapesSource(shapes, point, ratio, length, std::cin);
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "An error has occured: " << e.what();
  }
  catch (const std::exception &e)
  {
    std::cerr << "An error has occured: " << e.what();
    freeShapes(shapes, length);
    return 1;
  }

  if (length == 0)
  {
    std::cerr << "An error has occured: nothing to scale\n";
    freeShapes(shapes, length);
    return 1;
  }

  outputShapesSource(shapes, length, std::cout);
  std::cout << '\n';
  for (size_t i = 0; i < length; i++)
  {
    isoScale(shapes[i], point, ratio);
  }
  outputShapesSource(shapes, length, std::cout);
  std::cout << '\n';
  freeShapes(shapes, length);
}
