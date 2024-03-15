#include "output.hpp"
#include "othersFun.hpp"

namespace sivkov
{
  void output(std::ostream& out, const Shape* const* shapes, size_t count)
  {
    double sumOfArea = 0;
    for (size_t i = 0; i < count; ++i)
    {
      sumOfArea += shapes[i]->getArea();
    }
    out << sumOfArea;
    for (size_t i = 0; i < count; ++i)
    {
      outputFrameRectInfo(out, &shapes[i]);
    }
  }
}
