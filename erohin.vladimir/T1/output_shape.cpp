#include "output_shape.hpp"
#include <iostream>
#include "base-types.hpp"

void erohin::outputShape(std::ostream& output, const CompositeShape& composite_shape)
{
  output << composite_shape.getArea();
  rectangle_t frameRect = { 0.0, 0.0, { 0.0, 0.0 } };
  for (size_t i = 0; i < composite_shape.size(); ++i)
  {
    frameRect = composite_shape[i]->getFrameRect();
    output << " ";
    output << frameRect.pos.x - frameRect.width / 2.0 << " ";
    output << frameRect.pos.y - frameRect.height / 2.0 << " ";
    output << frameRect.pos.x + frameRect.width / 2.0 << " ";
    output << frameRect.pos.y + frameRect.height / 2.0;
  }
}
