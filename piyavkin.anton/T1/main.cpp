#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "isoscale.hpp"
#include "parallelogram.hpp"
#include "inputshape.hpp"
#include "output.hpp"
#include "compositeshape.hpp"

int main()
{
  try
  {
    using namespace piyavkin;
    CompositeShape cs;
    inputShape(std::cin, cs);
    double k = 0;
    point_t center = {0, 0};
    std::cin >> center.x >> center.y >> k;
    std::cout << std::fixed;
    std::cout.precision(1);
    output(std::cout, cs);
    std::cout << '\n';
    for (size_t i = 0; i < cs.size(); ++i)
    {
      isoScale(std::addressof(cs[i]), center, k);
    }
    output(std::cout, cs);
    std::cout << '\n';
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
