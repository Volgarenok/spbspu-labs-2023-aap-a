#include "output_shape.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>
#include "base-types.hpp"

void erohin::outputShape(std::ostream& output, const erohin::Shape* shape)
{
    output << std::fixed;
    output.precision(1);
    output << shape->getArea() << " ";
    erohin::rectangle_t frameRect = shape->getFrameRect();
    output << frameRect.pos.x - frameRect.width / 2.0 << " ";
    output << frameRect.pos.y - frameRect.height / 2.0 << " ";
    output << frameRect.pos.x + frameRect.width / 2.0 << " ";
    output << frameRect.pos.y + frameRect.height / 2.0;
}
