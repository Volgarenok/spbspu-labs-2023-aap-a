#include "outputResults.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

void isaychev::outputResults(std::ostream & out, const CompositeShape & cShape)
{
  out << cShape.getArea();
  for (size_t j = 0; j < cShape.size(); j++)
  {
    rectangle_t rect = cShape[j].getFrameRect();
    out << " " << std::round((rect.pos.x - (rect.width / 2)) * 10) / 10;
    out << " " << std::round((rect.pos.y - (rect.height / 2)) * 10) / 10;
    out << " " << std::round((rect.pos.x + (rect.width / 2)) * 10) / 10;
    out << " " << std::round((rect.pos.y + (rect.height / 2)) * 10) / 10;
  }
}
