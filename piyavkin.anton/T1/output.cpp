#include "output.hpp"

void piyavkin::output(std::ostream& out, const CompositeShape& shapes)
{
  if (shapes.empty())
  {
    throw std::logic_error("No figures");
  }
  out << shapes.getArea();
  for (size_t i = 0; i < shapes.size(); ++i)
  {
    out << " ";
    out << shapes[i].getFrameRect().pos.x - shapes[i].getFrameRect().width / 2 << " ";
    out << shapes[i].getFrameRect().pos.y - shapes[i].getFrameRect().height / 2 << " ";
    out << shapes[i].getFrameRect().pos.x + shapes[i].getFrameRect().width / 2 << " ";
    out << shapes[i].getFrameRect().pos.y + shapes[i].getFrameRect().height / 2;
  }
}

