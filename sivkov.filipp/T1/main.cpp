#include "concave.hpp"
#include "complexquad.hpp"
#include "inputShape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "scale.hpp"
#include "othersFun.hpp"
#include "output.hpp"
#include <iostream>

int main()
{
  Shape** figures = nullptr;
  size_t count = 0;
  try
  {

    figures = inputShape(std::cin, count);
    double k = 0;
    point_t center = { 0, 0 };
    std::cin >> center.x >> center.y >> k;
    std::cout << std::fixed;
    std::cout.precision(1);
    output(std::cout, figures, count);
    std::cout << '\n';
    for (size_t i = 0; i < count; ++i)
    {
      scale(figures[i], center, k);
    }
    output(std::cout, figures, count);
    std::cout << '\n';
    for (size_t i = 0; i < count; ++i)
    {
      delete figures[i];
    }
    delete[] figures;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    if (figures != nullptr)
    {
      for (size_t i = 0; i < count; ++i)
      {
        delete figures[i];
      }
      delete[] figures;
    }
  }
  return 0;
}